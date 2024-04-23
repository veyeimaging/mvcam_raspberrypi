/*

Copyright (c) 2021, xumm,Tianjin Zhonanyijia Tech.
All rights reserved.

*/

#ifndef MV_SC535_MODES_H_
#define MV_SC535_MODES_H_
#include "mv_regs.h"   

#define SC535_FULL_WIDTH   2432
#define SC535_FULL_HEIGHT  2048

struct sensor_regs raw_sc535_common_init[] =
{
    
};

struct sensor_regs raw_sc535_full_8bit_2lane_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x0},
    {0xFFFE,100},//sleep 100ms
    {Lane_Num,0x2},
    {0xFFFE,100},//sleep 100ms
    {Image_Acquisition, 0x01},  /* start */

};

struct sensor_regs raw_sc535_full_10bit_2lane_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x1},
    {0xFFFE,100},//sleep 100ms
    {Lane_Num,0x2},
    {0xFFFE,100},//sleep 100ms
    {Image_Acquisition, 0x01},  /* start */

};

struct sensor_regs raw_sc535_full_12bit_2lane_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x2},
    {0xFFFE,100},//sleep 100ms
    {Lane_Num,0x2},
    {0xFFFE,100},//sleep 100ms
    {Image_Acquisition, 0x01},  /* start */
};

struct sensor_regs raw_sc535_full_8bit_4lane_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x0},
    {0xFFFE,100},//sleep 100ms
    {Lane_Num,0x4},
    {0xFFFE,100},//sleep 100ms
    {Image_Acquisition, 0x01},  /* start */

};

struct sensor_regs raw_sc535_full_10bit_4lane_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x1},
    {0xFFFE,100},//sleep 100ms
    {Lane_Num,0x4},
    {0xFFFE,100},//sleep 100ms
    {Image_Acquisition, 0x01},  /* start */

};

struct sensor_regs raw_sc535_full_12bit_4lane_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x2},
    {0xFFFE,100},//sleep 100ms
    {Lane_Num,0x4},
    {0xFFFE,100},//sleep 100ms
    {Image_Acquisition, 0x01},  /* start */
};

//default value
struct sensor_regs raw_sc535_roi_regs[] = 
{
    {ROI_Offset_X, 0x00},
    {ROI_Offset_Y, 0x00},
    {ROI_Width, SC535_FULL_WIDTH},
    {0xFFFE,10},//sleep 10ms
    {ROI_Height, SC535_FULL_HEIGHT},
};

struct mode_def raw_sc535_modes[] = {

    //mode0 --2lan raw8
    {
      .regs          = raw_sc535_full_8bit_2lane_regs,
      .num_regs      = NUM_ELEMENTS(raw_sc535_full_8bit_2lane_regs),
      
      .width         = SC535_FULL_WIDTH,//
      .height        = SC535_FULL_HEIGHT,//
      .encoding      = 0,//,
      .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,
      .native_bit_depth = 8,// 
      .image_id      = 0x2A,//raw8
      .data_lanes    = 2,
      .min_vts       = 1118,//1118,
      .line_time_ns  = 14815,//1456 pixels per line
      .timing        = {0, 0, 0, 0, 0},
      .term          = {0, 0},
      .black_level   = 0,
   },

    //mode1 --2lan raw10    
   {
      .regs          = raw_sc535_full_10bit_2lane_regs,
      .num_regs      = NUM_ELEMENTS(raw_sc535_full_10bit_2lane_regs),
      
      .width         = SC535_FULL_WIDTH,//
      .height        = SC535_FULL_HEIGHT,//
      .encoding      = 0,//MMAL_ENCODING_Y10,
      .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,
      .native_bit_depth = 10,// 
      .image_id      = 0x2B,//raw10
      .data_lanes    = 2,
      .min_vts       = 1118,//1118,
      .line_time_ns  = 14815,//1456 pixels per line
      .timing        = {0, 0, 0, 0, 0},
      .term          = {0, 0},
      .black_level   = 0,
   },

   //mode2 --2lan raw12    
   {
      .regs          = raw_sc535_full_12bit_2lane_regs,
      .num_regs      = NUM_ELEMENTS(raw_sc535_full_12bit_2lane_regs),
      
      .width         = SC535_FULL_WIDTH,//
      .height        = SC535_FULL_HEIGHT,//
      .encoding      = 0,//MMAL_ENCODING_Y10,
      .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,
      .native_bit_depth = 12,// 
      .image_id      = 0x2C,//raw12
      .data_lanes    = 2,
      .min_vts       = 1118,//1118,
      .line_time_ns  = 14815,//1456 pixels per line
      .timing        = {0, 0, 0, 0, 0},
      .term          = {0, 0},
      .black_level   = 0,
   },

   //mode3 --4lan raw8
    {
      .regs          = raw_sc535_full_8bit_2lane_regs,
      .num_regs      = NUM_ELEMENTS(raw_sc535_full_8bit_2lane_regs),
      
      .width         = SC535_FULL_WIDTH,//
      .height        = SC535_FULL_HEIGHT,//
      .encoding      = 0,//,
      .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,
      .native_bit_depth = 8,// 
      .image_id      = 0x2A,//raw8
      .data_lanes    = 4,
      .min_vts       = 1118,//1118,
      .line_time_ns  = 14815,//1456 pixels per line
      .timing        = {0, 0, 0, 0, 0},
      .term          = {0, 0},
      .black_level   = 0,
   },

    //mode4 --4lan raw10    
   {
      .regs          = raw_sc535_full_10bit_2lane_regs,
      .num_regs      = NUM_ELEMENTS(raw_sc535_full_10bit_2lane_regs),
      
      .width         = SC535_FULL_WIDTH,//
      .height        = SC535_FULL_HEIGHT,//
      .encoding      = 0,//MMAL_ENCODING_Y10,
      .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,
      .native_bit_depth = 10,// 
      .image_id      = 0x2B,//raw10
      .data_lanes    = 4,
      .min_vts       = 1118,//1118,
      .line_time_ns  = 14815,//1456 pixels per line
      .timing        = {0, 0, 0, 0, 0},
      .term          = {0, 0},
      .black_level   = 0,
   },

   //mode5 --2lan raw12    
   {
      .regs          = raw_sc535_full_12bit_2lane_regs,
      .num_regs      = NUM_ELEMENTS(raw_sc535_full_12bit_2lane_regs),
      
      .width         = SC535_FULL_WIDTH,//
      .height        = SC535_FULL_HEIGHT,//
      .encoding      = 0,//MMAL_ENCODING_Y10,
      .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,
      .native_bit_depth = 12,// 
      .image_id      = 0x2C,//raw12
      .data_lanes    = 4,
      .min_vts       = 1118,//1118,
      .line_time_ns  = 14815,//1456 pixels per line
      .timing        = {0, 0, 0, 0, 0},
      .term          = {0, 0},
      .black_level   = 0,
   },
};

struct sensor_regs raw_sc535_stop[] = {
      {Image_Acquisition, 0x00},          /* disable streaming  */
};

struct sensor_def raw_sc535 = {
      .name =                 "raw_sc535",
      .common_init =          raw_sc535_common_init,
      .num_common_init =      NUM_ELEMENTS(raw_sc535_common_init),
      .modes =                raw_sc535_modes,
      .num_modes =            NUM_ELEMENTS(raw_sc535_modes),
      .stop =                 raw_sc535_stop,
      .num_stop_regs =        NUM_ELEMENTS(raw_sc535_stop),

      .roi = raw_sc535_roi_regs,
	  .num_roi_regs = NUM_ELEMENTS(raw_sc535_roi_regs),
	  
      .i2c_addr =             0x3b,
      .i2c_addressing =       2,
      .i2c_data_size =        4,
      
      .i2c_ident_length =     1,
      
      .i2c_ident_reg =        Model_Name,
      .i2c_ident_value =      0x8535,

      .vflip_reg =            Image_Direction,
      .vflip_reg_bit =        1,
      .hflip_reg =            Image_Direction,
      .hflip_reg_bit =        0,
      //manual exp
      .exposure_reg =         0x0c10,
      .exposure_reg_num_bits = 32,
       //todo
      .vts_reg =              0x3018,
      .vts_reg_num_bits =     16,

      .gain_reg =             0x0c20,
      .gain_reg_num_bits =    32,
};

#endif

