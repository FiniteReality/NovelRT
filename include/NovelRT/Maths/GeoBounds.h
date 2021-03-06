// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_MATHS_GEOBOUNDS_H
#define NOVELRT_MATHS_GEOBOUNDS_H

#ifndef NOVELRT_H
#error Please do not include this directly. Use the centralised header (NovelRT.h) instead!
#endif

namespace NovelRT::Maths {
  class GeoBounds {
  private:
    GeoVector<float> _position;
    float _rotation;
    GeoVector<float> _size;
    GeoVector<float> _extents;

  public:
    GeoBounds(const GeoVector<float>& position, const GeoVector<float>& size, float rotation);
    bool pointIsWithinBounds(const GeoVector<float>& point) const;
    bool intersectsWith(const GeoBounds& otherBounds) const;
    GeoVector<float> getCornerInLocalSpace(int index) const;
    GeoVector<float> getCornerInWorldSpace(int index) const;
    GeoVector<float> getPosition() const;
    void setPosition(const GeoVector<float>& value);
    GeoVector<float> getSize() const;
    void setSize(const GeoVector<float>& value);
    float getRotation() const;
    void setRotation(float value);
    GeoVector<float> getExtents() const;

    inline bool operator==(const GeoBounds& other) const {
      return _position == other._position
          && _size == other._size
          && _rotation == other._rotation;
    }

    inline bool operator!=(const GeoBounds& other) const {
      return _position != other._position
        || _size != other._size
        || _rotation != other._rotation;
    }
  };
}

#endif //NOVELRT_MATHS_GEOBOUNDS_H
