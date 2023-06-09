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
#include <QWidget>
#include "View/LayoutView.h"
#include "View/Style.h"
#include "Utils/String.h"

namespace Rt2::View
{
    class TitleListWidget final : public QWidget
    {
    public:
        explicit TitleListWidget(
            const String&        titleText,
            const QWidgetList&   titleItems,
            const int&           textSize,
            const int&           maxHeight      = Style::Icon::BoundingHeight,
            const QMargins&      margin         = {0, 0, 0, 0},
            const QColor&        foreground     = Style::Window::Foreground,
            const QColor&        background     = Style::Window::Background,
            const Qt::Alignment& titleAlignment = {},
            QWidget*             parent         = nullptr);

        ~TitleListWidget() override = default;
    };



    class TitleListView final : public LayoutView
    {
        Q_OBJECT
    private:
        QLabel *_title{nullptr};

    public:
        explicit TitleListView(QWidget *parent = nullptr);

        ~TitleListView() override = default;

        void setTitle(const String &title) const;

        void setWidgetList(const QWidgetList &widgets) const;

    private:
        void construct();
    };
}  // namespace Rt2::View
