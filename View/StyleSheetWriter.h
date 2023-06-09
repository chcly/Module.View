/*
-------------------------------------------------------------------------------
    Copyright (c) Charles Carley.

  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#pragma once
#include <QPalette>

#include "Utils/StackStream.h"
#include "View/Definitions.h"

namespace Rt2::View
{
    class StyleSheetWriter
    {
    private:
        OutputStreamStack  _out;
        OutputStringStream _data;

        void writePaletteColorRole(QPalette::ColorRole cr);

    public:
        StyleSheetWriter();
        explicit StyleSheetWriter(OStream* stream);
        ~StyleSheetWriter();

        QString toString();

        void begin();

        void begin(const String& widget);

        void beginUniversal();

        void beginType(const String& type);

        void beginProperty(const String& type, const String& property, const String& value);

        void beginClass(const String& type);

        void beginClassId(const String& type, const String& id);

        void beginId(const String& type, const String& id);

        void beginId(const String& id);

        void outline(const qreal& v);

        void outlineColor(const QColor& col);
    
        void noOutline();

        void background(const QColor& col);

        void backgroundColor(const QColor& col);

        void backgroundImage(const String& url);

        void image(const String& url);

        void backgroundColor(const GradientBox& co, const GradientStops& stops);

        void backgroundColor(const QPalette::ColorRole& col);

        void selectionBackgroundColor(const QColor& col);

        void selectionColor(const QColor& col);

        void showSelectedDecoration(bool v);

        void noBorder();

        void border(const QColor& col, const QMargins &m);

        void border(const QColor& col, int l, int t, int r, int b);

        void border(const QColor& col, qreal size);

        void borderLeft(const QColor& col, qreal size);

        void borderRight(const QColor& col, qreal size);

        void borderTop(const QColor& col, qreal size);

        void borderBottom(const QColor& col, qreal size);

        void borderRadius(qreal size);

        void minSize(const QSizeF& sz);

        void minWidth(const qreal& sz);

        void minHeight(const qreal& sz);

        void maxSize(const QSizeF& sz);

        void maxWidth(const qreal& sz);

        void maxHeight(const qreal& sz);

        void opacity(const qreal& sz);

        void noBackground();

        void color(const QColor& col);

        void color(const QPalette::ColorRole& col);

        void fontSize(const int& size);

        void width(const int& size);

        void height(const int& size);

        void padding(const int& v);

        void padding(const int& l, const int& t, const int& r, const int& b);

        void padding(const QMargins &margins);

        void paddingLeft(const int& v);

        void paddingTop(const int& v);

        void paddingRight(const int& v);

        void paddingBottom(const int& v);

        void margin(const int& v);

        void margin(const QMargins &margins);

        void margin(const int& l, const int& t, const int& r, const int& b);

        void marginLeft(const int& v);

        void marginTop(const int& v);

        void marginRight(const int& v);

        void marginBottom(const int& v);

        void left(const int& v);

        void top(const int& v);

        void right(const int& v);

        void bottom(const int& v);

        void end();
    };
}  // namespace Rt2::View
