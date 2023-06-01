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
#include "View/DefaultStyleSheet.h"
#include "View/Colors.h"
#include "View/Metrics.h"
#include "View/Qu.h"
#include "View/StyleSheetWriter.h"

// manual process:
// + #define DefaultStyleSheetUpdate
// + Save the stream to a file.
// + Use ResourceCompiler to convert it.
// + Adjust the constant below.

namespace Rt2::View
{
#ifdef DefaultStyleSheetUpdate

    void DefaultStyleSheet::get(QString& dest)
    {
         //OutputFileStream stream("test.css");
        OutputStringStream stream;

        {
            StyleSheetWriter style(&stream);

            style.begin("*");
            style.noBorder();
            style.backgroundColor(Colors::Background);
            style.color(Colors::Foreground);
            style.fontSize(Metrics::defaultTextSize);
            style.end();

            style.begin("QMenu");
            style.backgroundColor(Colors::CtrlBackground.lighter(Colors::Lgt020));
            style.color(Colors::ForegroundLight);
            style.end();

            style.begin("QToolTip");
            style.backgroundColor(Colors::CtrlBackground.lighter(Colors::Lgt030));
            style.color(Colors::ForegroundLight);
            style.border(Colors::CtrlBackground.lighter(Colors::Lgt090), 1);
            style.borderRadius(4);
            style.padding(2);
            style.end();

            style.begin("QMenu::separator");
            style.margin(Metrics::indent);
            style.borderBottom(Colors::CtrlBackgroundLight.lighter(Colors::Lgt090), 1);
            style.height(Metrics::defaultTextSize);
            style.end();

            style.begin("QMenu::selected");
            style.backgroundColor(Colors::Accent);
            style.border(Colors::Accent.lighter(), 2);
            style.end();

            style.begin("QLineEdit");
            style.backgroundColor(Colors::CtrlBackground.darker(Colors::Drk010));
            style.noBorder();
            style.end();

            style.begin("QListView");
            style.selectionColor(Colors::Accent);
            style.selectionBackgroundColor(Colors::Accent);
            style.outline(0);
            style.noBorder();
            style.end();

            style.begin("QListView::item:selected");
            style.backgroundColor(Colors::Accent);
            style.border(Colors::Accent.lighter(), 1);
            style.color(Colors::ForegroundLight);
            style.end();

            style.begin("QListView::item:hover");
            style.backgroundColor(Colors::Accent);
            style.color(Colors::ForegroundLight);
            style.end();

            style.begin("QScrollBar:vertical");
            style.backgroundColor(Colors::CtrlBackground.darker(Colors::Drk010));
            style.border(Colors::CtrlBackground.darker(Colors::Drk010), 1);
            style.width(Metrics::scrollbarSize);
            style.minWidth(Metrics::scrollbarSize);
            style.end();

            style.begin("QScrollBar:horizontal");
            style.backgroundColor(Colors::CtrlBackground.darker(Colors::Drk010));
            style.border(Colors::CtrlBackground.darker(Colors::Drk010), 1);
            style.height(Metrics::scrollbarSize);
            style.minHeight(Metrics::scrollbarSize);
            style.end();

            style.begin("QScrollBar::add-line:horizontal");
            style.width(0);
            style.end();
            style.begin("QScrollBar::sub-line:horizontal");
            style.width(0);
            style.end();

            style.begin("QScrollBar::add-line:vertical");
            style.height(0);
            style.end();

            style.begin("QScrollBar::sub-line:vertical");
            style.height(0);
            style.end();

            style.begin("QScrollBar::add-page:vertical");
            style.noBorder();
            style.noBackground();
            style.end();

            style.begin("QScrollBar::sub-page:vertical");
            style.noBorder();
            style.noBackground();
            style.end();

            style.begin("QScrollBar::add-page:horizontal");
            style.noBorder();
            style.noBackground();
            style.end();
            style.begin("QScrollBar::sub-page:horizontal");
            style.noBorder();
            style.noBackground();
            style.end();

            style.begin("QScrollBar::handle:vertical");
            style.backgroundColor(Colors::CtrlBackgroundLight);
            style.border(Colors::BorderLight, 1);
            style.borderRadius(1);
            style.minWidth(Metrics::scrollbarSize);
            style.margin(Metrics::borderSizeTiny);
            style.end();

            style.begin("QScrollBar::handle:horizontal");
            style.backgroundColor(Colors::CtrlBackgroundLight);
            style.border(Colors::BorderLight, 1);
            style.borderRadius(1);
            style.minHeight(Metrics::scrollbarSize);
            style.margin(Metrics::borderSizeTiny);
            style.end();

            style.begin("QCheckBox");
            style.backgroundColor(Colors::CtrlBackgroundLight);
            style.border(Colors::BorderLight, 1);
            style.end();

            style.begin("QCheckBox::indicator:unchecked ");
            style.backgroundColor(Colors::CtrlBackgroundLight);
            style.border(Colors::BorderLight, 1);
            style.end();

            style.begin("QCheckBox::indicator:checked ");
            style.backgroundColor(Colors::Accent);
            style.color(Colors::CtrlBackgroundLight);
            style.border(Colors::BorderLight, 1);
            style.end();

            style.begin("QTreeWidget");
            style.showSelectedDecoration(true);
            style.backgroundColor(Colors::CtrlBackground);
            style.noBorder();
            style.noOutline();
            style.end();

            style.begin("QTreeWidget::branch:has-children:adjoins-item:closed");
            style.image(":/images/right.svg");
            style.end();

            style.begin("QTreeWidget::branch:has-children:adjoins-item:open");
            style.image(":/images/down.svg");
            style.end();

            style.begin("QTreeWidget::branch:!has-children:adjoins-item");
            style.image(":/images/stop.svg");
            style.end();

            style.begin("QTreeWidget::item");
            style.showSelectedDecoration(false);
            style.noBorder();
            style.noOutline();
            style.selectionBackgroundColor(Colors::Accent);
            style.end();

            style.begin("QTreeWidget::item::hover");
            style.noBorder();
            style.backgroundColor(Colors::Accent.lighter());
            style.backgroundColor(Colors::Accent.darker(Colors::Drk020));
            style.color(Colors::Foreground);
            style.noOutline();
            style.end();

            style.begin("QTreeWidget::item::selected");
            style.backgroundColor(Colors::Accent.darker(Colors::Drk010));
            style.color(Colors::Foreground);
            style.noOutline();
            style.end();

            style.begin("QSplitter::handle");
            style.backgroundColor(Colors::CtrlBackground.darker(Colors::Drk010));
            style.end();
            style.begin("QSplitter::handle:horizontal");
            style.width(Metrics::borderSizeThin);
            style.end();
            style.begin("QSplitter::handle:vertical");
            style.height(Metrics::borderSizeThin);
            style.end();

            style.begin("QTextEdit");
            style.backgroundColor(Colors::Border);
            style.noBorder();
            style.selectionBackgroundColor(Colors::Accent);
            style.selectionColor(Colors::ForegroundLight);
            style.color(Colors::Emphasis[3]);
            style.end();
        }
        dest = Qsu::to(stream.str());
    }
#else
    // clang-format off
    constexpr uint8_t DefaultStyle[2624] = {
           0x2a,0x7b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x6e,0x6f,0x6e,0x65,
           0x3b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,
           0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x32,0x32,0x32,0x32,0x32,0x35,0x3b,
           0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x39,0x41,0x39,0x38,0x39,0x37,
           0x3b,0x66,0x6f,0x6e,0x74,0x2d,0x73,0x69,0x7a,0x65,0x3a,0x41,0x70,
           0x74,0x3b,0x7d,0x51,0x4d,0x65,0x6e,0x75,0x7b,0x62,0x61,0x63,0x6b,
           0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,
           0x23,0x32,0x39,0x32,0x39,0x32,0x43,0x3b,0x63,0x6f,0x6c,0x6f,0x72,
           0x3a,0x23,0x43,0x41,0x43,0x38,0x43,0x37,0x3b,0x7d,0x51,0x54,0x6f,
           0x6f,0x6c,0x54,0x69,0x70,0x7b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,
           0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x32,0x43,
           0x32,0x43,0x33,0x30,0x3b,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x43,
           0x41,0x43,0x38,0x43,0x37,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,
           0x31,0x70,0x78,0x20,0x73,0x6f,0x6c,0x69,0x64,0x20,0x23,0x34,0x31,
           0x34,0x31,0x34,0x36,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x2d,0x72,
           0x61,0x64,0x69,0x75,0x73,0x3a,0x34,0x70,0x78,0x3b,0x70,0x61,0x64,
           0x64,0x69,0x6e,0x67,0x3a,0x32,0x70,0x78,0x3b,0x7d,0x51,0x4d,0x65,
           0x6e,0x75,0x3a,0x3a,0x73,0x65,0x70,0x61,0x72,0x61,0x74,0x6f,0x72,
           0x7b,0x6d,0x61,0x72,0x67,0x69,0x6e,0x3a,0x20,0x36,0x70,0x78,0x3b,
           0x62,0x6f,0x72,0x64,0x65,0x72,0x2d,0x62,0x6f,0x74,0x74,0x6f,0x6d,
           0x3a,0x31,0x70,0x78,0x20,0x73,0x6f,0x6c,0x69,0x64,0x20,0x23,0x35,
           0x30,0x35,0x30,0x35,0x35,0x3b,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,
           0x41,0x70,0x78,0x3b,0x7d,0x51,0x4d,0x65,0x6e,0x75,0x3a,0x3a,0x73,
           0x65,0x6c,0x65,0x63,0x74,0x65,0x64,0x7b,0x62,0x61,0x63,0x6b,0x67,
           0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,
           0x34,0x44,0x35,0x37,0x38,0x31,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,
           0x3a,0x32,0x70,0x78,0x20,0x73,0x6f,0x6c,0x69,0x64,0x20,0x23,0x37,
           0x33,0x38,0x33,0x43,0x31,0x3b,0x7d,0x51,0x4c,0x69,0x6e,0x65,0x45,
           0x64,0x69,0x74,0x7b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,
           0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x31,0x43,0x31,0x43,
           0x31,0x46,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x6e,0x6f,0x6e,
           0x65,0x3b,0x7d,0x51,0x4c,0x69,0x73,0x74,0x56,0x69,0x65,0x77,0x7b,
           0x73,0x65,0x6c,0x65,0x63,0x74,0x69,0x6f,0x6e,0x2d,0x63,0x6f,0x6c,
           0x6f,0x72,0x3a,0x23,0x34,0x44,0x35,0x37,0x38,0x31,0x3b,0x73,0x65,
           0x6c,0x65,0x63,0x74,0x69,0x6f,0x6e,0x2d,0x62,0x61,0x63,0x6b,0x67,
           0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,
           0x34,0x44,0x35,0x37,0x38,0x31,0x3b,0x6f,0x75,0x74,0x6c,0x69,0x6e,
           0x65,0x3a,0x30,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x6e,0x6f,
           0x6e,0x65,0x3b,0x7d,0x51,0x4c,0x69,0x73,0x74,0x56,0x69,0x65,0x77,
           0x3a,0x3a,0x69,0x74,0x65,0x6d,0x3a,0x73,0x65,0x6c,0x65,0x63,0x74,
           0x65,0x64,0x7b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,
           0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x34,0x44,0x35,0x37,0x38,
           0x31,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x31,0x70,0x78,0x20,
           0x73,0x6f,0x6c,0x69,0x64,0x20,0x23,0x37,0x33,0x38,0x33,0x43,0x31,
           0x3b,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x43,0x41,0x43,0x38,0x43,
           0x37,0x3b,0x7d,0x51,0x4c,0x69,0x73,0x74,0x56,0x69,0x65,0x77,0x3a,
           0x3a,0x69,0x74,0x65,0x6d,0x3a,0x68,0x6f,0x76,0x65,0x72,0x7b,0x62,
           0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,
           0x6f,0x72,0x3a,0x23,0x34,0x44,0x35,0x37,0x38,0x31,0x3b,0x63,0x6f,
           0x6c,0x6f,0x72,0x3a,0x23,0x43,0x41,0x43,0x38,0x43,0x37,0x3b,0x7d,
           0x51,0x53,0x63,0x72,0x6f,0x6c,0x6c,0x42,0x61,0x72,0x3a,0x76,0x65,
           0x72,0x74,0x69,0x63,0x61,0x6c,0x7b,0x62,0x61,0x63,0x6b,0x67,0x72,
           0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x31,
           0x43,0x31,0x43,0x31,0x46,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,
           0x31,0x70,0x78,0x20,0x73,0x6f,0x6c,0x69,0x64,0x20,0x23,0x31,0x43,
           0x31,0x43,0x31,0x46,0x3b,0x77,0x69,0x64,0x74,0x68,0x3a,0x43,0x70,
           0x78,0x3b,0x6d,0x69,0x6e,0x2d,0x77,0x69,0x64,0x74,0x68,0x3a,0x31,
           0x32,0x70,0x78,0x3b,0x7d,0x51,0x53,0x63,0x72,0x6f,0x6c,0x6c,0x42,
           0x61,0x72,0x3a,0x68,0x6f,0x72,0x69,0x7a,0x6f,0x6e,0x74,0x61,0x6c,
           0x7b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,
           0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x31,0x43,0x31,0x43,0x31,0x46,0x3b,
           0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x31,0x70,0x78,0x20,0x73,0x6f,
           0x6c,0x69,0x64,0x20,0x23,0x31,0x43,0x31,0x43,0x31,0x46,0x3b,0x68,
           0x65,0x69,0x67,0x68,0x74,0x3a,0x43,0x70,0x78,0x3b,0x6d,0x69,0x6e,
           0x2d,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x31,0x32,0x70,0x78,0x3b,
           0x7d,0x51,0x53,0x63,0x72,0x6f,0x6c,0x6c,0x42,0x61,0x72,0x3a,0x3a,
           0x61,0x64,0x64,0x2d,0x6c,0x69,0x6e,0x65,0x3a,0x68,0x6f,0x72,0x69,
           0x7a,0x6f,0x6e,0x74,0x61,0x6c,0x7b,0x77,0x69,0x64,0x74,0x68,0x3a,
           0x30,0x70,0x78,0x3b,0x7d,0x51,0x53,0x63,0x72,0x6f,0x6c,0x6c,0x42,
           0x61,0x72,0x3a,0x3a,0x73,0x75,0x62,0x2d,0x6c,0x69,0x6e,0x65,0x3a,
           0x68,0x6f,0x72,0x69,0x7a,0x6f,0x6e,0x74,0x61,0x6c,0x7b,0x77,0x69,
           0x64,0x74,0x68,0x3a,0x30,0x70,0x78,0x3b,0x7d,0x51,0x53,0x63,0x72,
           0x6f,0x6c,0x6c,0x42,0x61,0x72,0x3a,0x3a,0x61,0x64,0x64,0x2d,0x6c,
           0x69,0x6e,0x65,0x3a,0x76,0x65,0x72,0x74,0x69,0x63,0x61,0x6c,0x7b,
           0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x30,0x70,0x78,0x3b,0x7d,0x51,
           0x53,0x63,0x72,0x6f,0x6c,0x6c,0x42,0x61,0x72,0x3a,0x3a,0x73,0x75,
           0x62,0x2d,0x6c,0x69,0x6e,0x65,0x3a,0x76,0x65,0x72,0x74,0x69,0x63,
           0x61,0x6c,0x7b,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x30,0x70,0x78,
           0x3b,0x7d,0x51,0x53,0x63,0x72,0x6f,0x6c,0x6c,0x42,0x61,0x72,0x3a,
           0x3a,0x61,0x64,0x64,0x2d,0x70,0x61,0x67,0x65,0x3a,0x76,0x65,0x72,
           0x74,0x69,0x63,0x61,0x6c,0x7b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,
           0x6e,0x6f,0x6e,0x65,0x3b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,
           0x6e,0x64,0x3a,0x6e,0x6f,0x6e,0x65,0x3b,0x7d,0x51,0x53,0x63,0x72,
           0x6f,0x6c,0x6c,0x42,0x61,0x72,0x3a,0x3a,0x73,0x75,0x62,0x2d,0x70,
           0x61,0x67,0x65,0x3a,0x76,0x65,0x72,0x74,0x69,0x63,0x61,0x6c,0x7b,
           0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x6e,0x6f,0x6e,0x65,0x3b,0x62,
           0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x3a,0x6e,0x6f,0x6e,
           0x65,0x3b,0x7d,0x51,0x53,0x63,0x72,0x6f,0x6c,0x6c,0x42,0x61,0x72,
           0x3a,0x3a,0x61,0x64,0x64,0x2d,0x70,0x61,0x67,0x65,0x3a,0x68,0x6f,
           0x72,0x69,0x7a,0x6f,0x6e,0x74,0x61,0x6c,0x7b,0x62,0x6f,0x72,0x64,
           0x65,0x72,0x3a,0x6e,0x6f,0x6e,0x65,0x3b,0x62,0x61,0x63,0x6b,0x67,
           0x72,0x6f,0x75,0x6e,0x64,0x3a,0x6e,0x6f,0x6e,0x65,0x3b,0x7d,0x51,
           0x53,0x63,0x72,0x6f,0x6c,0x6c,0x42,0x61,0x72,0x3a,0x3a,0x73,0x75,
           0x62,0x2d,0x70,0x61,0x67,0x65,0x3a,0x68,0x6f,0x72,0x69,0x7a,0x6f,
           0x6e,0x74,0x61,0x6c,0x7b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x6e,
           0x6f,0x6e,0x65,0x3b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,
           0x64,0x3a,0x6e,0x6f,0x6e,0x65,0x3b,0x7d,0x51,0x53,0x63,0x72,0x6f,
           0x6c,0x6c,0x42,0x61,0x72,0x3a,0x3a,0x68,0x61,0x6e,0x64,0x6c,0x65,
           0x3a,0x76,0x65,0x72,0x74,0x69,0x63,0x61,0x6c,0x7b,0x62,0x61,0x63,
           0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,
           0x3a,0x23,0x32,0x41,0x32,0x41,0x32,0x44,0x3b,0x62,0x6f,0x72,0x64,
           0x65,0x72,0x3a,0x31,0x70,0x78,0x20,0x73,0x6f,0x6c,0x69,0x64,0x20,
           0x23,0x31,0x45,0x31,0x45,0x32,0x31,0x3b,0x62,0x6f,0x72,0x64,0x65,
           0x72,0x2d,0x72,0x61,0x64,0x69,0x75,0x73,0x3a,0x31,0x70,0x78,0x3b,
           0x6d,0x69,0x6e,0x2d,0x77,0x69,0x64,0x74,0x68,0x3a,0x31,0x32,0x70,
           0x78,0x3b,0x6d,0x61,0x72,0x67,0x69,0x6e,0x3a,0x20,0x31,0x70,0x78,
           0x3b,0x7d,0x51,0x53,0x63,0x72,0x6f,0x6c,0x6c,0x42,0x61,0x72,0x3a,
           0x3a,0x68,0x61,0x6e,0x64,0x6c,0x65,0x3a,0x68,0x6f,0x72,0x69,0x7a,
           0x6f,0x6e,0x74,0x61,0x6c,0x7b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,
           0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x32,0x41,
           0x32,0x41,0x32,0x44,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x31,
           0x70,0x78,0x20,0x73,0x6f,0x6c,0x69,0x64,0x20,0x23,0x31,0x45,0x31,
           0x45,0x32,0x31,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x2d,0x72,0x61,
           0x64,0x69,0x75,0x73,0x3a,0x31,0x70,0x78,0x3b,0x6d,0x69,0x6e,0x2d,
           0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x31,0x32,0x70,0x78,0x3b,0x6d,
           0x61,0x72,0x67,0x69,0x6e,0x3a,0x20,0x31,0x70,0x78,0x3b,0x7d,0x51,
           0x43,0x68,0x65,0x63,0x6b,0x42,0x6f,0x78,0x7b,0x62,0x61,0x63,0x6b,
           0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,
           0x23,0x32,0x41,0x32,0x41,0x32,0x44,0x3b,0x62,0x6f,0x72,0x64,0x65,
           0x72,0x3a,0x31,0x70,0x78,0x20,0x73,0x6f,0x6c,0x69,0x64,0x20,0x23,
           0x31,0x45,0x31,0x45,0x32,0x31,0x3b,0x7d,0x51,0x43,0x68,0x65,0x63,
           0x6b,0x42,0x6f,0x78,0x3a,0x3a,0x69,0x6e,0x64,0x69,0x63,0x61,0x74,
           0x6f,0x72,0x3a,0x75,0x6e,0x63,0x68,0x65,0x63,0x6b,0x65,0x64,0x20,
           0x7b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,
           0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x32,0x41,0x32,0x41,0x32,0x44,0x3b,
           0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x31,0x70,0x78,0x20,0x73,0x6f,
           0x6c,0x69,0x64,0x20,0x23,0x31,0x45,0x31,0x45,0x32,0x31,0x3b,0x7d,
           0x51,0x43,0x68,0x65,0x63,0x6b,0x42,0x6f,0x78,0x3a,0x3a,0x69,0x6e,
           0x64,0x69,0x63,0x61,0x74,0x6f,0x72,0x3a,0x63,0x68,0x65,0x63,0x6b,
           0x65,0x64,0x20,0x7b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,
           0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x34,0x44,0x35,0x37,
           0x38,0x31,0x3b,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x32,0x41,0x32,
           0x41,0x32,0x44,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x31,0x70,
           0x78,0x20,0x73,0x6f,0x6c,0x69,0x64,0x20,0x23,0x31,0x45,0x31,0x45,
           0x32,0x31,0x3b,0x7d,0x51,0x54,0x72,0x65,0x65,0x57,0x69,0x64,0x67,
           0x65,0x74,0x7b,0x73,0x68,0x6f,0x77,0x2d,0x64,0x65,0x63,0x6f,0x72,
           0x61,0x74,0x69,0x6f,0x6e,0x2d,0x73,0x65,0x6c,0x65,0x63,0x74,0x65,
           0x64,0x3a,0x31,0x3b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,
           0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x32,0x32,0x32,0x32,
           0x32,0x35,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x6e,0x6f,0x6e,
           0x65,0x3b,0x6f,0x75,0x74,0x6c,0x69,0x6e,0x65,0x3a,0x6e,0x6f,0x6e,
           0x65,0x3b,0x7d,0x51,0x54,0x72,0x65,0x65,0x57,0x69,0x64,0x67,0x65,
           0x74,0x3a,0x3a,0x62,0x72,0x61,0x6e,0x63,0x68,0x3a,0x68,0x61,0x73,
           0x2d,0x63,0x68,0x69,0x6c,0x64,0x72,0x65,0x6e,0x3a,0x61,0x64,0x6a,
           0x6f,0x69,0x6e,0x73,0x2d,0x69,0x74,0x65,0x6d,0x3a,0x63,0x6c,0x6f,
           0x73,0x65,0x64,0x7b,0x69,0x6d,0x61,0x67,0x65,0x3a,0x75,0x72,0x6c,
           0x28,0x3a,0x2f,0x69,0x6d,0x61,0x67,0x65,0x73,0x2f,0x72,0x69,0x67,
           0x68,0x74,0x2e,0x73,0x76,0x67,0x29,0x3b,0x7d,0x51,0x54,0x72,0x65,
           0x65,0x57,0x69,0x64,0x67,0x65,0x74,0x3a,0x3a,0x62,0x72,0x61,0x6e,
           0x63,0x68,0x3a,0x68,0x61,0x73,0x2d,0x63,0x68,0x69,0x6c,0x64,0x72,
           0x65,0x6e,0x3a,0x61,0x64,0x6a,0x6f,0x69,0x6e,0x73,0x2d,0x69,0x74,
           0x65,0x6d,0x3a,0x6f,0x70,0x65,0x6e,0x7b,0x69,0x6d,0x61,0x67,0x65,
           0x3a,0x75,0x72,0x6c,0x28,0x3a,0x2f,0x69,0x6d,0x61,0x67,0x65,0x73,
           0x2f,0x64,0x6f,0x77,0x6e,0x2e,0x73,0x76,0x67,0x29,0x3b,0x7d,0x51,
           0x54,0x72,0x65,0x65,0x57,0x69,0x64,0x67,0x65,0x74,0x3a,0x3a,0x62,
           0x72,0x61,0x6e,0x63,0x68,0x3a,0x21,0x68,0x61,0x73,0x2d,0x63,0x68,
           0x69,0x6c,0x64,0x72,0x65,0x6e,0x3a,0x61,0x64,0x6a,0x6f,0x69,0x6e,
           0x73,0x2d,0x69,0x74,0x65,0x6d,0x7b,0x69,0x6d,0x61,0x67,0x65,0x3a,
           0x75,0x72,0x6c,0x28,0x3a,0x2f,0x69,0x6d,0x61,0x67,0x65,0x73,0x2f,
           0x73,0x74,0x6f,0x70,0x2e,0x73,0x76,0x67,0x29,0x3b,0x7d,0x51,0x54,
           0x72,0x65,0x65,0x57,0x69,0x64,0x67,0x65,0x74,0x3a,0x3a,0x69,0x74,
           0x65,0x6d,0x7b,0x73,0x68,0x6f,0x77,0x2d,0x64,0x65,0x63,0x6f,0x72,
           0x61,0x74,0x69,0x6f,0x6e,0x2d,0x73,0x65,0x6c,0x65,0x63,0x74,0x65,
           0x64,0x3a,0x30,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x6e,0x6f,
           0x6e,0x65,0x3b,0x6f,0x75,0x74,0x6c,0x69,0x6e,0x65,0x3a,0x6e,0x6f,
           0x6e,0x65,0x3b,0x73,0x65,0x6c,0x65,0x63,0x74,0x69,0x6f,0x6e,0x2d,
           0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,
           0x6c,0x6f,0x72,0x3a,0x23,0x34,0x44,0x35,0x37,0x38,0x31,0x3b,0x7d,
           0x51,0x54,0x72,0x65,0x65,0x57,0x69,0x64,0x67,0x65,0x74,0x3a,0x3a,
           0x69,0x74,0x65,0x6d,0x3a,0x3a,0x68,0x6f,0x76,0x65,0x72,0x7b,0x62,
           0x6f,0x72,0x64,0x65,0x72,0x3a,0x6e,0x6f,0x6e,0x65,0x3b,0x62,0x61,
           0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,
           0x72,0x3a,0x23,0x37,0x33,0x38,0x33,0x43,0x31,0x3b,0x62,0x61,0x63,
           0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,
           0x3a,0x23,0x33,0x37,0x33,0x45,0x35,0x43,0x3b,0x63,0x6f,0x6c,0x6f,
           0x72,0x3a,0x23,0x39,0x41,0x39,0x38,0x39,0x37,0x3b,0x6f,0x75,0x74,
           0x6c,0x69,0x6e,0x65,0x3a,0x6e,0x6f,0x6e,0x65,0x3b,0x7d,0x51,0x54,
           0x72,0x65,0x65,0x57,0x69,0x64,0x67,0x65,0x74,0x3a,0x3a,0x69,0x74,
           0x65,0x6d,0x3a,0x3a,0x73,0x65,0x6c,0x65,0x63,0x74,0x65,0x64,0x7b,
           0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,
           0x6c,0x6f,0x72,0x3a,0x23,0x34,0x30,0x34,0x39,0x36,0x42,0x3b,0x63,
           0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x39,0x41,0x39,0x38,0x39,0x37,0x3b,
           0x6f,0x75,0x74,0x6c,0x69,0x6e,0x65,0x3a,0x6e,0x6f,0x6e,0x65,0x3b,
           0x7d,0x51,0x53,0x70,0x6c,0x69,0x74,0x74,0x65,0x72,0x3a,0x3a,0x68,
           0x61,0x6e,0x64,0x6c,0x65,0x7b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,
           0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x31,0x43,
           0x31,0x43,0x31,0x46,0x3b,0x7d,0x51,0x53,0x70,0x6c,0x69,0x74,0x74,
           0x65,0x72,0x3a,0x3a,0x68,0x61,0x6e,0x64,0x6c,0x65,0x3a,0x68,0x6f,
           0x72,0x69,0x7a,0x6f,0x6e,0x74,0x61,0x6c,0x7b,0x77,0x69,0x64,0x74,
           0x68,0x3a,0x32,0x70,0x78,0x3b,0x7d,0x51,0x53,0x70,0x6c,0x69,0x74,
           0x74,0x65,0x72,0x3a,0x3a,0x68,0x61,0x6e,0x64,0x6c,0x65,0x3a,0x76,
           0x65,0x72,0x74,0x69,0x63,0x61,0x6c,0x7b,0x68,0x65,0x69,0x67,0x68,
           0x74,0x3a,0x32,0x70,0x78,0x3b,0x7d,0x51,0x54,0x65,0x78,0x74,0x45,
           0x64,0x69,0x74,0x7b,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,
           0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x30,0x46,0x30,0x46,
           0x31,0x32,0x3b,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x6e,0x6f,0x6e,
           0x65,0x3b,0x73,0x65,0x6c,0x65,0x63,0x74,0x69,0x6f,0x6e,0x2d,0x62,
           0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,
           0x6f,0x72,0x3a,0x23,0x34,0x44,0x35,0x37,0x38,0x31,0x3b,0x73,0x65,
           0x6c,0x65,0x63,0x74,0x69,0x6f,0x6e,0x2d,0x63,0x6f,0x6c,0x6f,0x72,
           0x3a,0x23,0x43,0x41,0x43,0x38,0x43,0x37,0x3b,0x63,0x6f,0x6c,0x6f,
           0x72,0x3a,0x23,0x38,0x42,0x38,0x39,0x38,0x38,0x3b,0x7d,
    };
    // clang-format on

    void DefaultStyleSheet::get(QString& dest)
    {
        String str;
        str.assign((const char*)DefaultStyle, 2624);
        dest = Qsu::to(str);
    }
#endif

}  // namespace Rt2::View
