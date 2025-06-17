package gstreamer

/*
#cgo pkg-config: gstreamer-1.0
#include "gst_wrapper.h"
*/
import "C"
import "fmt"

func InitPipeline() error {
    if C.gst_init_and_build_pipeline() == 0 {
        return fmt.Errorf("failed to build pipeline")
    }
    return nil
}

func GetPattern() int {
    return int(C.gst_get_pattern_property())
}

func Cleanup() {
    C.gst_cleanup_pipeline()
}
