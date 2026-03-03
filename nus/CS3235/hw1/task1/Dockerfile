FROM ubuntu:18.04

RUN apt-get update -y \
    && apt-get install -y openssh-server \
    && apt-get install -y gcc build-essential \
    python3 python3-pip python3-dev \
    libffi-dev libssl-dev gdb

RUN pip3 install --upgrade pip \
    && pip3 install pwntools

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get -y install checksecurity

# Create a non-root user
RUN useradd -d /home/student -ms /bin/bash student && echo 'student:stupwd' | chpasswd

RUN cp -R /lib* /home/student && \
    cp -R /usr/lib* /home/student/usr

RUN mkdir /home/student/dev && \
    mknod /home/student/dev/null c 1 3 && \
    mknod /home/student/dev/zero c 1 5 && \
    mknod /home/student/dev/random c 1 8 && \
    mknod /home/student/dev/urandom c 1 9 && \
    chmod 666 /home/student/dev/*

RUN mkdir /home/student/bin && \
    mkdir /home/student/etc && \
    mkdir /home/student/src && \
    cp /bin/* /home/student/bin && \
    cp /usr/bin/id /home/student/bin/id && \
    cp /usr/bin/whoami /home/student/bin/whoami && \
    cp /etc/shadow /home/student/etc && \
    cp /etc/passwd /home/student/etc && \
    rm /home/student/bin/rm

# Set binary and flag
WORKDIR /home/student

COPY src /home/student/src
RUN cd /home/student/src && make

RUN chown -R root:root /home/student/challenge
RUN chmod 444 /home/student/src/flag.txt
RUN chmod u+s /home/student/challenge

# Set up SSH configuration
USER root
COPY src/setup-ssh.sh /usr/local/bin/setup-ssh.sh
RUN chmod +x /usr/local/bin/setup-ssh.sh
RUN /usr/local/bin/setup-ssh.sh

# Expose SSH port
EXPOSE 22

# Start SSH service
CMD ["/usr/sbin/sshd", "-D"]
