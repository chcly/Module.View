#include "View/TextEditView.h"
#include <QBoxLayout>
#include <QLineEdit>
#include <QPainter>
#include <QPainterPath>
#include <QWidget>
#include "View/Colors.h"
#include "View/Metrics.h"
#include "View/Qu.h"
#include "ViewModel/ViewModel.h"

namespace Rt2::View
{
    TextEditView::TextEditView(QWidget* parent) :
        View(parent)
    {
        _edit = new QLineEdit(this);
        construct();
    }

    void TextEditView::setText(const String& text)
    {
        _viewModel.setValue(text);
    }

    String TextEditView::text() const
    {
        return _viewModel.value();
    }

    void TextEditView::addOutput(const ObserverType& type)
    {
        _viewModel.addOutput(type);
    }

    void TextEditView::construct()
    {
        constructView(_edit);

        setBorderColor(Colors::BorderDark);
        setBackgroundColor(Colors::Transparent);
        setColor(QPalette::Highlight, Colors::Accent);

        _edit->setFrame(false);
        Qu::setBackground(_edit, Colors::Transparent);
        bind();
    }

    void TextEditView::bind()
    {
        _viewModel.addInput(
            [=](const String& text)
            {
                if (_edit)
                    _edit->setText(Qsu::to(text));
            });

        connect(_edit,
                &QLineEdit::textEdited,
                this,
                &TextEditView::textChanged);
    }

    void TextEditView::textChanged(const QString& val)
    {
        _viewModel.setValue(Qsu::from(val), ViewModel::OUTPUT);
    }

    void TextEditView::paintEvent(QPaintEvent* event)
    {
        QPainter paint(this);
        paint.setRenderHint(QPainter::Antialiasing);

        QRectF ctx = {0, 0, (qreal)width(), (qreal)height()};

        ctx = ctx.marginsRemoved(contentsMargins());

        QColor col = palette().color(QPalette::Window);

        QLinearGradient gradient(ctx.topLeft(), ctx.bottomLeft());
        gradient.setColorAt(0.0, col.darker(Colors::Drk050));
        gradient.setColorAt(0.2, col.darker(Colors::Drk010));
        gradient.setColorAt(1.0, col);

        paint.fillRect(ctx, col.darker(150));
        paint.setPen(QPen(col.lighter(), Metrics::borderSizeTiny));
        paint.drawRect(ctx);
    }
}  // namespace Rt2::View