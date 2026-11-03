#!/bin/bash
# --- Real-time OS Performance Evaluation Script ---
set -euo pipefail
echo "=================================================="
echo "
SYSTEM PERFORMANCE CORE METRICS
"
echo "=================================================="
echo "Timestamp: $(date '+%Y-%m-%d %H:%M:%S')"
echo ""
# 1. Capture CPU Utilization Metrics safely across platforms
echo "--- CPU Usage Analysis ---"
if command -v mpstat >/dev/null 2>&1; then
mpstat 1 1 | awk '/Average:/ {printf "Total CPU Utilization: %.2f%%\n", 100 - $NF}'
else
# Fallback to top parsing if sysstat tools are absent
top -bn1 | grep "Cpu(s)" | awk '{printf "Total CPU Utilization: %.2f%%\n", $2 + $4}'
fi
echo ""
# 2. Extract Virtual & Physical RAM State
echo "--- Memory Resource Allocation ---"
free -h | awk '
/Mem:/ {print "Physical Memory -> Total: "$2" | Used: "$3" | Available: "$7}
/Swap:/ {print "Swap Allocation -> Total: "$2" | Used: "$3" | Free: "$4}
'
echo ""
# 3. Target top 5 resource-consuming execution spaces
echo "--- Top 5 Memory Consuming Processes ---"
echo "PID
USER
%CPU %MEM COMMAND"
ps -eo pid,user,pcpu,pmem,comm --sort=-pmem | head -n 6 | tail -n 5
echo "=================================================="
