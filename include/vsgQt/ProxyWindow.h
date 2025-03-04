#pragma once

/* <editor-fold desc="MIT License">

Copyright(c) 2021 Robert Osfield

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

</editor-fold> */

#include <vsg/viewer/Window.h>
#include <vsgQt/Export.h>

namespace vsgQt
{

    // forward declare
    class ViewerWindow;

    class VSGQT_DECLSPEC ProxyWindow : public vsg::Inherit<vsg::Window, ProxyWindow>
    {
    public:
        ProxyWindow(ViewerWindow* win, vsg::ref_ptr<vsg::WindowTraits> traits);

        ProxyWindow() = delete;
        ProxyWindow(const Window&) = delete;
        ProxyWindow operator=(const Window&) = delete;

        bool visible() const override { return _window != nullptr; }
        bool valid() const override { return _window != nullptr; }

        bool pollEvents(vsg::UIEvents& events) override;

        bool resized() const override;

        void resize() override;

        virtual const char* instanceExtensionSurfaceName() const override;

        vsg::UIEvents bufferedEvents;

    protected:
        virtual void _initSurface() override;

        virtual ~ProxyWindow() override;

        ViewerWindow* _window = nullptr;
    };

} // namespace vsgQt
