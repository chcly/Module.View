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
#include "StyleSheetWriter.h"
#include "Qu.h"
#include "Utils/StackStream.h"
#include "Utils/StreamConverters/Hex.h"

namespace Rt2::View
{
    StyleSheetWriter::StyleSheetWriter()
    {
        _out._push(&_data);
    }

    StyleSheetWriter::StyleSheetWriter(OStream* stream)
    {
        _out._push(stream);
    }

    StyleSheetWriter::~StyleSheetWriter()
    {
        _out.flush();
    }

    QString StyleSheetWriter::toString()
    {
        _out.flush();
        return Qsu::to(_data.str());
    }

    void StyleSheetWriter::begin()
    {
        _out.print('{');
    }

    void StyleSheetWriter::begin(const String& widget)
    {
        _out.print(widget, '{');
    }

    void StyleSheetWriter::beginUniversal()
    {
        _out.print('*', '{');
    }

    void StyleSheetWriter::beginType(const String& type)
    {
        _out.print(type, '{');
    }

    void StyleSheetWriter::beginProperty(const String& type, const String& property, const String& value)
    {
        _out.print(type, '[', property, '=', '"', value, '"', ']', '{');
    }

    void StyleSheetWriter::beginClass(const String& type)
    {
        _out.print('.', type, '{');
    }

    void StyleSheetWriter::beginClassId(const String& type, const String& id)
    {
        if (type.empty())
            beginId(id);
        else
            _out.print('.', type, '#', id, '{');
    }

    void StyleSheetWriter::beginId(const String& type, const String& id)
    {
        if (type.empty())
            beginId(id);
        else
            _out.print(type, '#', id, '{');
    }

    void StyleSheetWriter::beginId(const String& id)
    {
        _out.print('#', id, '{');
    }

    void StyleSheetWriter::outline(const qreal& v)
    {
        _out.print("outline:", v, ';');
    }

    void StyleSheetWriter::outlineColor(const QColor& col)
    {
        _out.print("outline-color:#",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ';');
    }

    void StyleSheetWriter::noOutline()
    {
        _out.print("outline:none;");
    }

    void StyleSheetWriter::background(const QColor& col)
    {
        _out.print("background:#",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ';');
    }

    void StyleSheetWriter::backgroundColor(const QColor& col)
    {
        _out.print("background-color:#",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ';');
    }

    void StyleSheetWriter::backgroundImage(const String& url)
    {
        _out.print("background-image:url", '(', url, ')', ';');
    }

    void StyleSheetWriter::image(const String& url)
    {
        _out.print("image:url", '(', url, ')', ';');
    }

    void StyleSheetWriter::backgroundColor(const GradientBox& co, const GradientStops& stops)
    {
        _out.print("background-color:qlineargradient(");
        _out.print("x1:", co.x1, ",y1:", co.y1, ",x2:", co.x2, ",y2:", co.y2);

        for (const auto& [offs, col] : stops)
        {
            _out.print(',',
                       "stop:",
                       offs,
                       " #",
                       Hex((uint8_t)Min(col.red(), 0xFF)),
                       Hex((uint8_t)Min(col.green(), 0xFF)),
                       Hex((uint8_t)Min(col.blue(), 0xFF)));
        }
        _out.print(");");
    }

    void StyleSheetWriter::backgroundColor(const QPalette::ColorRole& col)
    {
        _out.print("background-color:");
        writePaletteColorRole(col);
    }

    void StyleSheetWriter::selectionBackgroundColor(const QColor& col)
    {
        _out.print("selection-background-color:#",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ';');
    }

    void StyleSheetWriter::selectionColor(const QColor& col)
    {
        _out.print("selection-color:#",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ';');
    }

    void StyleSheetWriter::showSelectedDecoration(bool v)
    {
        _out.print("show-decoration-selected:", (v ? 1 : 0), ';');
    }

    void StyleSheetWriter::noBorder()
    {
        _out.print("border:none;");
    }

    void StyleSheetWriter::border(const QColor& col, const QMargins& m)
    {
        border(col, m.left(), m.top(), m.right(), m.bottom());
    }

    void StyleSheetWriter::border(const QColor& col, int l, int t, int r, int b)
    {
        if (l == r && t == b && l == b)
        {
            if (l > 0)
                border(col, l);
            else
                noBorder();
        }
        else
        {
            if (l > 0) borderLeft(col, l);
            if (t > 0) borderTop(col, t);
            if (r > 0) borderRight(col, r);
            if (b > 0) borderBottom(col, b);
        }
    }

    void StyleSheetWriter::border(const QColor& col, qreal size)
    {
        _out.print("border:",
                   size,
                   "px solid #",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ";");
    }

    void StyleSheetWriter::borderLeft(const QColor& col, qreal size)
    {
        _out.print("border-left:",
                   size,
                   "px solid #",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ";");
    }

    void StyleSheetWriter::borderRight(const QColor& col, qreal size)
    {
        _out.print("border-right:",
                   size,
                   "px solid #",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ";");
    }

    void StyleSheetWriter::borderTop(const QColor& col, qreal size)
    {
        _out.print("border-top:",
                   size,
                   "px solid #",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ";");
    }

    void StyleSheetWriter::borderBottom(const QColor& col, qreal size)
    {
        _out.print("border-bottom:",
                   size,
                   "px solid #",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ";");
    }

    void StyleSheetWriter::borderRadius(qreal size)
    {
        _out.print("border-radius:", size, "px;");
    }

    void StyleSheetWriter::minSize(const QSizeF& sz)
    {
        minWidth(sz.width());
        minHeight(sz.height());
    }

    void StyleSheetWriter::minWidth(const qreal& sz)
    {
        _out.print("min-width:", sz, "px;");
    }

    void StyleSheetWriter::minHeight(const qreal& sz)
    {
        _out.print("min-height:", sz, "px;");
    }

    void StyleSheetWriter::maxSize(const QSizeF& sz)
    {
        maxWidth(sz.width());
        maxHeight(sz.height());
    }

    void StyleSheetWriter::maxWidth(const qreal& sz)
    {
        _out.print("max-width:", sz, "px;");
    }

    void StyleSheetWriter::maxHeight(const qreal& sz)
    {
        _out.print("max-height:", sz, "px;");
    }

    void StyleSheetWriter::opacity(const qreal& sz)
    {
        _out.print("opacity:", sz, ";");
    }

    void StyleSheetWriter::noBackground()
    {
        _out.print("background:none;");
    }

    void StyleSheetWriter::color(const QColor& col)
    {
        _out.print("color:#",
                   Hex((uint8_t)Min(col.red(), 0xFF)),
                   Hex((uint8_t)Min(col.green(), 0xFF)),
                   Hex((uint8_t)Min(col.blue(), 0xFF)),
                   ';');
    }

    void StyleSheetWriter::color(const QPalette::ColorRole& col)
    {
        _out.print("color:");
        writePaletteColorRole(col);
    }

    void StyleSheetWriter::fontSize(const int& size)
    {
        _out.print("font-size:", size, "pt;");
    }

    void StyleSheetWriter::width(const int& size)
    {
        _out.print("width:", size, "px;");
    }

    void StyleSheetWriter::height(const int& size)
    {
        _out.print("height:", size, "px;");
    }

    void StyleSheetWriter::padding(const int& v)
    {
        _out.print("padding:", v, "px;");
    }

    void StyleSheetWriter::padding(const int& l, const int& t, const int& r, const int& b)
    {
        if (l == r && t == b && l == b)
        {
            if (l > 0) padding(l);
        }
        else
        {
            if (l > 0) paddingLeft(l);
            if (t > 0) paddingTop(t);
            if (r > 0) paddingRight(r);
            if (b > 0) paddingBottom(b);
        }
    }

    void StyleSheetWriter::padding(const QMargins& margins)
    {
        padding(margins.left(), margins.top(), margins.right(), margins.bottom());
    }

    void StyleSheetWriter::paddingLeft(const int& v)
    {
        _out.print("padding-left:", v, "px;");
    }

    void StyleSheetWriter::paddingTop(const int& v)
    {
        _out.print("padding-top:", v, "px;");
    }

    void StyleSheetWriter::paddingRight(const int& v)
    {
        _out.print("padding-right:", v, "px;");
    }

    void StyleSheetWriter::paddingBottom(const int& v)
    {
        _out.print("padding-bottom:", v, "px;");
    }

    void StyleSheetWriter::margin(const int& v)
    {
        _out.print("margin: ", v, "px;");
    }

    void StyleSheetWriter::margin(const QMargins& margins)
    {
        margin(margins.left(),
               margins.top(),
               margins.right(),
               margins.bottom());
    }

    void StyleSheetWriter::margin(const int& l, const int& t, const int& r, const int& b)
    {
        if (l == r && t == b && l == b)
        {
            if (l > 0) margin(l);
        }
        else
        {
            if (l > 0) marginLeft(l);
            if (t > 0) marginTop(t);
            if (r > 0) marginRight(r);
            if (b > 0) marginBottom(b);
        }
    }

    void StyleSheetWriter::marginLeft(const int& v)
    {
        _out.print("margin-left:", v, "px;");
    }

    void StyleSheetWriter::marginTop(const int& v)
    {
        _out.print("margin-top:", v, "px;");
    }

    void StyleSheetWriter::marginRight(const int& v)
    {
        _out.print("margin-right:", v, "px;");
    }

    void StyleSheetWriter::marginBottom(const int& v)
    {
        _out.print("margin-bottom:", v, "px;");
    }

    void StyleSheetWriter::left(const int& v)
    {
        _out.print("left:", v, "px;");
    }

    void StyleSheetWriter::top(const int& v)
    {
        _out.print("top:", v, "px;");
    }

    void StyleSheetWriter::right(const int& v)
    {
        _out.print("right:", v, "px;");
    }

    void StyleSheetWriter::bottom(const int& v)
    {
        _out.print("bottom:", v, "px;");
    }

    void StyleSheetWriter::writePaletteColorRole(QPalette::ColorRole cr)
    {
        _out.print("palette(");
        switch (cr)
        {
        case QPalette::WindowText:
            _out.print("window-text");
            break;
        case QPalette::Button:
            _out.print("button");
            break;
        case QPalette::Light:
            _out.print("light");
            break;
        case QPalette::Midlight:
            _out.print("midlight");
            break;
        case QPalette::Dark:
            _out.print("dark");
            break;
        case QPalette::Mid:
            _out.print("mid");
            break;
        case QPalette::Text:
            _out.print("text");
            break;
        case QPalette::BrightText:
            _out.print("bright-text");
            break;
        case QPalette::ButtonText:
            _out.print("button-text");
            break;
        case QPalette::Base:
            _out.print("base");
            break;
        case QPalette::Window:
            _out.print("window");
            break;
        case QPalette::Shadow:
            _out.print("shadow");
            break;
        case QPalette::Highlight:
            _out.print("highlight");
            break;
        case QPalette::HighlightedText:
            _out.print("highlighted-text");
            break;
        case QPalette::Link:
            _out.print("link");
            break;
        case QPalette::LinkVisited:
            _out.print("link-visited");
            break;
        case QPalette::AlternateBase:
            _out.print("alternate-base");
            break;
        default:
        case QPalette::PlaceholderText:
        case QPalette::ToolTipText:
        case QPalette::ToolTipBase:
        case QPalette::NColorRoles:
        case QPalette::NoRole:
            _out.print("base");
            break;
        }
        _out.print(");");
    }

    void StyleSheetWriter::end()
    {
        _out.print('}');
    }
}  // namespace Rt2::View
