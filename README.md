Task


🔹 Problem 1: Drop TCP Packets on a Specific Port (Default: 4040)

Objective: Write an eBPF program that drops all TCP packets targeting a specific port (4040 by default), with the port configurable from user space.

Solution & Outcome:

    Implemented an eBPF program using the tc hook (SEC("tc")) to drop TCP packets at the network ingress point.

    A BPF map (BPF_MAP_TYPE_ARRAY) was used to store the port number dynamically set via user-space C code (set_port_user.c).

    The program was tested on a GCP VM using tc (since XDP is not supported on VirtioNet).

    Verified that traffic to port 4040 was dropped, and other ports passed successfully.

✅ Result: Kernel-level TCP filtering on a configurable port was successfully achieved using eBPF and tc.
🔹 Problem 2: Drop All Ports Except 4040 for a Specific Process

Objective: Create an eBPF program that only allows TCP connections to port 4040 for a specific process (e.g., myprocess), dropping all other traffic for that process.

Solution & Outcome:

    Used the cgroup/connect4 hook (SEC("cgroup/connect4")) to intercept outgoing TCP connections.

    Leveraged bpf_get_current_comm() to identify the running process.

    Traffic was filtered based on both the process name and destination port.

    Attached the eBPF program to a dedicated cgroup using bpftool and tested it with a custom myprocess C binary.

    Confirmed that:

        Port 4040 was allowed for myprocess

        All other ports were blocked for myprocess

        Other processes remained unaffected

✅ Result: Successfully enforced fine-grained, per-process TCP filtering via eBPF and cgroups (v2).
🔹 Problem 3: Explain a Go Concurrency Code Snippet

Objective: Analyze and explain a Go code snippet involving channels, goroutines, and concurrency behavior.

Solution & Outcome:

    Explained how the code uses a buffered channel of func() to distribute work across 4 goroutines.

    Identified the reason why "HERE1" was not printed: the main program exits before any goroutine pulls the function from the channel.

    Proposed solutions such as adding a sync.WaitGroup or time.Sleep to ensure goroutines complete.

    Explained the use of make(chan func(), 10) for buffered task queuing, and the worker pool pattern via for loop.

✅ Result: Clear understanding of Go concurrency, channels, anonymous functions, and program lifecycle.
