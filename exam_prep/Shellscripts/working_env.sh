#!/bin/bash
# --- Secure Sandboxed Permissions Deployment Script ---
set -euo pipefail
TARGET_DIR="./secure_sandbox"
echo "Initializing Secure Filesystem Sandbox inside: ${TARGET_DIR}..."
# Setup clean working space environment
if [ -d "$TARGET_DIR" ]; then
rm -rf "$TARGET_DIR"
fi
mkdir -p "$TARGET_DIR"
# Step 1: Create Files & Directories
touch "${TARGET_DIR}/read_only.txt"
touch "${TARGET_DIR}/full_access.txt"
touch "${TARGET_DIR}/restricted.txt"
mkdir -p "${TARGET_DIR}/protected_dir"
# Step 2: Implement Granular Access Controls via Octal Bitmasks
echo "Applying Access Control Policies..."
# File 1: Read-only for owner, completely inaccessible to group and others (0400)
chmod 400 "${TARGET_DIR}/read_only.txt"
# File 2: Read, Write, and Execute for owner, Read/Execute for group, no access for others (0750)
chmod 750 "${TARGET_DIR}/full_access.txt"
# File 3: Read and Write for owner, Read-only for group and others (0644)
chmod 644 "${TARGET_DIR}/restricted.txt"
# Directory: Full management capability for owner, restricted browsing otherwise (0711)
chmod 711 "${TARGET_DIR}/protected_dir"
# Step 3: Parse and Verify System Properties
echo ""
echo "=== Verified Object Permissions Audit ==="
ls -ld "${TARGET_DIR}/"* | awk '{print $1 " | Owner: " $3 " | Group: " $4 " | Target: " $9}'
echo "========================================="

