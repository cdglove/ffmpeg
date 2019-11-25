/*
 * Xiph cgvc decoder using cgvc
 * Copyright (c) 2019 Chris Glover
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <cgvc/cgvc.h>
#include "avcodec.h"
#include "internal.h"
#include "libavutil/intreadwrite.h"

// struct cgvc_dec_context {
// };

// static int ff_cgvc_error_to_averror(int err)
// {
//     switch (err) {
//         case cgvc_BAD_ARG:          return AVERROR(EINVAL);
// #ifdef cgvc_BUFFER_TOO_SMALL
//         case cgvc_BUFFER_TOO_SMALL: return AVERROR(ENOBUFS);
// #endif
//         case cgvc_INTERNAL_ERROR:   return AVERROR(EFAULT);
//         case cgvc_CORRUPTED_DATA:   return AVERROR_INVALIDDATA;
//         case cgvc_UNIMPLEMENTED:    return AVERROR(ENOSYS);
// #ifdef ENOTRECOVERABLE
//         case cgvc_INVALID_STATE:    return AVERROR(ENOTRECOVERABLE);
// #endif
//         case cgvc_ALLOC_FAIL:       return AVERROR(ENOMEM);
//         default:                    return AVERROR(EINVAL);
//     }
// }

// static int ff_cgvc_bitstream_version_hack(cgvcMode *mode)
// {
//     cgvcHeader header = { .version_id = 0 };
//     cgvc_header_init(&header, mode, 960, 2);
//     return header.version_id;
// }

static av_cold int cgvc_dec_init(AVCodecContext *c)
{
    // struct cgvc_dec_context *cgvc = c->priv_data;
    // int err;

    // if (!c->channels || !c->frame_size ||
    //     c->frame_size > INT_MAX / sizeof(int16_t) / c->channels)
    //     return AVERROR(EINVAL);
    // cgvc->mode = cgvc_mode_create(c->sample_rate, c->frame_size, &err);
    // if (!cgvc->mode)
    //     return ff_cgvc_error_to_averror(err);
    // cgvc->dec = cgvc_decoder_create_custom(cgvc->mode, c->channels, &err);
    // if (!cgvc->dec) {
    //     cgvc_mode_destroy(cgvc->mode);
    //     return ff_cgvc_error_to_averror(err);
    // }
    // if (c->extradata_size >= 4) {
    //     cgvc->discard = AV_RL32(c->extradata);
    //     if (cgvc->discard < 0 || cgvc->discard >= c->frame_size) {
    //         av_log(c, AV_LOG_WARNING,
    //                "Invalid overlap (%d), ignored.\n", cgvc->discard);
    //         cgvc->discard = 0;
    //     }
    // }
    // if (c->extradata_size >= 8) {
    //     unsigned version = AV_RL32(c->extradata + 4);
    //     unsigned lib_version = ff_cgvc_bitstream_version_hack(cgvc->mode);
    //     if (version != lib_version)
    //         av_log(c, AV_LOG_WARNING,
    //                "cgvc bitstream version 0x%x may be "
    //                "improperly decoded by cgvc for version 0x%x.\n",
    //                version, lib_version);
    // }
    // c->sample_fmt = AV_SAMPLE_FMT_S16;
    return 0;
}

static av_cold int cgvc_dec_close(AVCodecContext *c)
{
    // struct cgvc_dec_context *cgvc = c->priv_data;

    // cgvc_decoder_destroy(cgvc->dec);
    // cgvc_mode_destroy(cgvc->mode);
    return 0;
}

static int cgvc_dec_decode(AVCodecContext *c, void *data,
                              int *got_frame_ptr, AVPacket *pkt)
{
    // struct cgvc_dec_context *cgvc = c->priv_data;
    // AVFrame *frame = data;
    // int err;
    // int16_t *pcm;

    // frame->nb_samples = c->frame_size;
    // if ((err = ff_get_buffer(c, frame, 0)) < 0)
    //     return err;
    // pcm = (int16_t *)frame->data[0];
    // err = cgvc_decode(cgvc->dec, pkt->data, pkt->size, pcm, c->frame_size);
    // if (err < 0)
    //     return ff_cgvc_error_to_averror(err);
    // if (cgvc->discard) {
    //     frame->nb_samples -= cgvc->discard;
    //     memmove(pcm, pcm + cgvc->discard * c->channels,
    //             frame->nb_samples * c->channels * sizeof(int16_t));
    //     cgvc->discard = 0;
    // }
    // *got_frame_ptr = 1;
    // return pkt->size;
    return 0;
}

AVCodec ff_cgvc_decoder = {
    .name           = "cgvc",
    .long_name      = NULL_IF_CONFIG_SMALL("Chris Glover Video Codec"),
    .type           = AVMEDIA_TYPE_VIDEO,
    .id             = AV_CODEC_ID_CGVC,
    .priv_data_size = 0, //sizeof(struct cgvc_dec_context),
    .init           = cgvc_dec_init,
    .close          = cgvc_dec_close,
    .decode         = cgvc_dec_decode,
    //.capabilities   = AV_CODEC_CAP_DR1,
    .wrapper_name   = "cgvc",
};
