# go-c

A minimal example project demonstrating interoperability between Go and C using cgo, featuring a GStreamer pipeline written in C.

## Features

- Integrate Go code with a GStreamer pipeline in C
- Simple build and usage instructions
- Ready to use in a devcontainer environment
- Initialize Go module: `go mod init gostreamercgo`
- Build the project: `make`
- Run tests: `make test`
- All commands should be run inside the devcontainer, the tests invoke Go code that calls into the C code
