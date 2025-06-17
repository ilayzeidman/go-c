package gstreamer

import "testing"

func TestPatternProperty(t *testing.T) {
    if err := InitPipeline(); err != nil {
        t.Fatalf("Pipeline init failed: %v", err)
    }
    defer Cleanup()

    got := GetPattern()
    expected := 0 // default value for videotestsrc

    if got != expected {
        t.Errorf("Pattern property = %d; want %d", got, expected)
    }
}
