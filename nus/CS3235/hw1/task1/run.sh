docker build -t task1 .
docker run -d -p 2221:22 --name task1-container --privileged task1
docker exec -it task1-container bash -c "echo 0 > /proc/sys/kernel/randomize_va_space"
