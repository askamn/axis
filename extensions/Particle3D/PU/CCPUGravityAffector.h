/****************************************************************************
 Copyright (C) 2013 Henry van Merode. All rights reserved.
 Copyright (c) 2015-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 https://axys1.github.io/

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __AX_PU_PARTICLE_3D_GRAVITY_AFFECTOR_H__
#define __AX_PU_PARTICLE_3D_GRAVITY_AFFECTOR_H__

#include "extensions/Particle3D/PU/CCPUAffector.h"
#include "base/ccTypes.h"

NS_AX_BEGIN

class AX_EX_DLL PUGravityAffector : public PUAffector
{
public:
    // Constants
    static const float DEFAULT_GRAVITY;

    static PUGravityAffector* create();

    virtual void preUpdateAffector(float deltaTime) override;
    virtual void updatePUAffector(PUParticle3D* particle, float deltaTime) override;

    /**
     */
    float getGravity() const;
    void setGravity(float gravity);

    virtual void copyAttributesTo(PUAffector* affector) override;

    PUGravityAffector();
    virtual ~PUGravityAffector();

protected:
    float _gravity;
};
NS_AX_END

#endif