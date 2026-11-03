
#!/bin/bash

# Network Latency Benchmarking Pipeline

TARGET="${1:-google.com}"

echo "======================================"
echo " Network Latency Benchmarking"
echo " Target: $TARGET"
echo "======================================"

# Execute traceroute and limit output
traceroute -n -m 10 -q 1 -w 2 "$TARGET" 2>&1 |
head -n 15 |
awk '
/^[[:space:]]*[0-9]+[[:space:]]/ {
    hop = $1

    if ($0 ~ /\*/) {
        printf "Hop %s: No response\n", hop
    }
    else {
        for (i = 2; i <= NF; i++) {
            if ($i ~ /^[0-9]+([.][0-9]+)?$/ && $(i+1) == "ms") {
                printf "Hop %s: %s ms\n", hop, $i
                break
            }
        }
    }
}'

echo "======================================"
echo " Benchmark completed"

