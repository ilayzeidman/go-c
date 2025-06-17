FROM golang:1.22

RUN apt-get update && apt-get install -y \
    libgstreamer1.0-dev \
    gstreamer1.0-tools \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good \
    gcc \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace