/****************************************************************************
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

 Ideas taken from:
 - GamePlay3D: http://gameplay3d.org/
 - OGRE3D: http://www.ogre3d.org/
 - Qt3D: http://qt-project.org/
 ****************************************************************************/
#pragma once

#include <string>
#include "renderer/CCRenderState.h"
#include "base/CCRef.h"
#include "platform/CCPlatformMacros.h"
#include "base/CCVector.h"

NS_AX_BEGIN

class Pass;
class Material;

namespace backend
{
class ProgramState;
}

/// Technique
class AX_DLL Technique : public Ref
{
    friend class Material;
    friend class Renderer;
    friend class Pass;
    friend class MeshCommand;
    friend class Mesh;
    friend class RenderState;

public:
    /** Creates a new Technique with a GLProgramState.
     Method added to support legacy code
     */
    static Technique* createWithProgramState(Material* parent, backend::ProgramState* state);
    static Technique* create(Material* parent);

    /** Adds a new pass to the Technique.
     Order matters. First added, first rendered
     */
    void addPass(Pass* pass);

    /** Returns the name of the Technique */
    std::string getName() const;

    /** Returns the Pass at given index */
    Pass* getPassByIndex(ssize_t index) const;

    /** Returns the number of Passes in the Technique */
    ssize_t getPassCount() const;

    /** Returns the list of passes */
    const Vector<Pass*>& getPasses() const;

    /** Returns a new clone of the Technique */
    Technique* clone() const;

    void setMaterial(Material* material) { _material = material; }

    RenderState::StateBlock& getStateBlock() { return _renderState.getStateBlock(); }

protected:
    Technique();
    ~Technique();
    bool init(Material* parent);

    void setName(std::string_view name);
    RenderState _renderState;
    std::string _name;
    Vector<Pass*> _passes;

    Material* _material = nullptr;
};

NS_AX_END
