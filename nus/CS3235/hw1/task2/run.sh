docker run -d -p 2222:22 \
    -v $(dirname $(pwd))/answer:/answer \
    -v $(pwd):/task2 \
    --name task2-container \
    --privileged \
    task2
docker exec -it task2-container bash -c "echo 0 > /proc/sys/kernel/randomize_va_space"
