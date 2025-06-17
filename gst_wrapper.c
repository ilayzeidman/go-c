// gst_wrapper.c
#include <gst/gst.h>
#include "gst_wrapper.h"

static GstElement *pipeline = NULL;
static GstElement *source = NULL;

int gst_init_and_build_pipeline() {
    gst_init(NULL, NULL);

    source = gst_element_factory_make("videotestsrc", "source");
    GstElement *sink = gst_element_factory_make("fakesink", "sink");

    if (!source || !sink) {
        return 0; // error
    }

    pipeline = gst_pipeline_new("test-pipeline");
    if (!pipeline) {
        return 0;
    }

    gst_bin_add_many(GST_BIN(pipeline), source, sink, NULL);
    if (!gst_element_link(source, sink)) {
        return 0;
    }

    return 1; // success
}

int gst_get_pattern_property() {
    gint pattern = 0;
    g_object_get(G_OBJECT(source), "pattern", &pattern, NULL);
    return pattern;
}

void gst_cleanup_pipeline() {
    if (pipeline) {
        gst_object_unref(pipeline);
        pipeline = NULL;
        source = NULL;
    }
}
