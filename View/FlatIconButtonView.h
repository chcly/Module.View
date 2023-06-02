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
#include "View/IconFontMapping.h"
#include "View/View.h"

class QLabel;
class QPushButton;

namespace Rt2::View
{
    class FlatIconButtonStates;

    class FlatIconButtonView final : public View
    {
        Q_OBJECT
    private:
        BoolModel             _model;
        QLabel*               _button{nullptr};
        FlatIconButtonStates* _states{nullptr};
        int                   _state{NONE};

    public:
        explicit FlatIconButtonView(IconMap icon, QWidget* parent = nullptr);

        ~FlatIconButtonView() override;

        void setFlatColor(const QColor& col) const;

        void setHighlightColor(const QColor& col) const;

        void setIconSize(int size) const;

        void addOutput(const BoolModel::Observer& ot);

    private:
        void construct(IconMap icon);

        void mousePressEvent(QMouseEvent* event) override;

        void mouseReleaseEvent(QMouseEvent* event) override;

        void enterEvent(QEnterEvent* event) override;

        void leaveEvent(QEvent* event) override;
    };

}  // namespace Rt2::View