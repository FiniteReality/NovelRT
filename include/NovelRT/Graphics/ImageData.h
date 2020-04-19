// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_GRAPHICS_IMAGEDATA_H
#define NOVELRT_GRAPHICS_IMAGEDATA_H

namespace NovelRT::Graphics {
  struct ImageData {
    uint32_t width;
    uint32_t height;
    png_byte colourType;
    png_byte bitDepth;
    png_bytep* rowPointers = nullptr; //just following the example here
  };
}

#endif // !NOVELRT_GRAPHICS_IMAGEDATA_H
