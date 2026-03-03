docker run -d -p 2223:22 \
    -v $(dirname $(pwd))/answer:/answer \
    -v $(pwd):/task3 \
    --name task3-container \
    --cap-add=SYS_PTRACE \
    --security-opt seccomp=unconfined \
    --privileged \
    task3
docker exec -it task3-container bash -c "echo 0 > /proc/sys/kernel/randomize_va_space"
