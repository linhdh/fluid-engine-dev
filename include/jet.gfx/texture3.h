// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_GFX_TEXTURE3_H_
#define INCLUDE_JET_GFX_TEXTURE3_H_

#include <jet.gfx/texture.h>
#include <jet/array_view.h>
#include <jet/macros.h>
#include <jet/matrix.h>

#include <memory>

namespace jet {
namespace gfx {

class Renderer;

//! Abstract base class for 3-D textures.
class Texture3 {
 public:
    //! Default constructor.
    Texture3();

    //! Destructor.
    virtual ~Texture3();

    //! Updates current texture with given 32-bit color data.
    virtual void update(const ConstArrayView3<Vector4F>& data) = 0;

    //! Updates current texture with given 8-bit color data.
    virtual void update(const ConstArrayView3<Vector4B>& data) = 0;

    //! Clears the contents.
    void clear();

    //! Sets the texture with given 32-bit color data and size.
    void setTexture(const ConstArrayView3<Vector4F>& data);

    //! Sets the texture with given 8-bit color data and size.
    void setTexture(const ConstArrayView3<Vector4B>& data);

    //! Binds the texture to given renderer with slot ID.
    void bind(Renderer* renderer, unsigned int slotId);

    //! Returns the size of the texture.
    const Vector3UZ& size() const;

    //! Returns the sampling mode of the texture.
    const TextureSamplingMode& samplingMode() const;

    //! Sets the sampling mode of the texture.
    void setSamplingMode(const TextureSamplingMode& mode);

 protected:
    //! Called when clear() is invoked.
    virtual void onClear() = 0;

    //! Called when resize(...) is invoked.
    virtual void onSetTexture(const ConstArrayView3<Vector4F>& data) = 0;

    //! Called when resize(...) is invoked.
    virtual void onSetTexture(const ConstArrayView3<Vector4B>& data) = 0;

    //! Called when bind(...) is invoked.
    virtual void onBind(Renderer* renderer, unsigned int slotId) = 0;

    //! Called when sampling mode has changed.
    virtual void onSamplingModeChanged(const TextureSamplingMode& mode) = 0;

 private:
    Vector3UZ _size;
    TextureSamplingMode _samplingMode = TextureSamplingMode::kNearest;
};

using Texture3Ptr = std::shared_ptr<Texture3>;

}  // namespace gfx
}  // namespace jet

#endif  // INCLUDE_JET_GFX_TEXTURE3_H_