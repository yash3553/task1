#include <bpf/libbpf.h>
#include <stdio.h>
#include <bpf/bpf.h>  
#include <errno.h>
int main() {
    int map_fd = bpf_obj_get("/sys/fs/bpf/blocked_port_map");
    __u32 key = 0;
    __u16 val = 4040;
    bpf_map_update_elem(map_fd, &key, &val, BPF_ANY);
    return 0;
}

