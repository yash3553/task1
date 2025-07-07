#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_endian.h>

char LICENSE[] SEC("license") = "GPL";

SEC("cgroup/connect4")
int block_other_ports(struct bpf_sock_addr *ctx) {
    char comm[16];
    bpf_get_current_comm(&comm, sizeof(comm));

    // Match only process named "myprocess"
    if (__builtin_memcmp(comm, "myprocess", 9) == 0) {
        if (ctx->user_port == bpf_htons(4040)) {
            return 1; // allow
        } else {
            return 0; // block
        }
    }

    return 1; // allow everything else
}

