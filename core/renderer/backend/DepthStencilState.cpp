/****************************************************************************
 Copyright (c) 2018-2019 Xiamen Yaji Software Co., Ltd.

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

#include "DepthStencilState.h"
#include "RenderTarget.h"

NS_AX_BACKEND_BEGIN

bool StencilDescriptor::operator==(const StencilDescriptor& rhs) const
{
    return (
        stencilFailureOperation == rhs.stencilFailureOperation && depthFailureOperation == rhs.depthFailureOperation &&
        depthStencilPassOperation == rhs.depthStencilPassOperation &&
        stencilCompareFunction == rhs.stencilCompareFunction && readMask == rhs.readMask && writeMask == rhs.writeMask);
}

DepthStencilState::~DepthStencilState() {}

void DepthStencilState::update(const DepthStencilDescriptor& dsDesc)
{
    _depthStencilInfo        = dsDesc;
    _isBackFrontStencilEqual = dsDesc.backFaceStencil == dsDesc.frontFaceStencil;
}

NS_AX_BACKEND_END
