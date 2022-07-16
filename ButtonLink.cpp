#include "ButtonLink.hpp"
#include <QApplication>
#include <QStyle>

ButtonLink::ButtonLink(QWidget *parent)
   : QLabel(parent)
{
}

ButtonLink::ButtonLink(const QString &text, QWidget *parent)
   : QLabel(text, parent)
{
}

ButtonLink::ButtonLink(const QString &text, const QVariant &data, QWidget *parent)
   : QLabel(text, parent)
   , mData(data)
{
   setContentsMargins(QMargins());
}

void ButtonLink::mousePressEvent(QMouseEvent *e)
{
   Q_UNUSED(e);

   if (isEnabled())
      mPressed = true;
}

void ButtonLink::mouseReleaseEvent(QMouseEvent *event)
{
   Q_UNUSED(event);

   if (isEnabled() && mPressed)
      emit clicked();
}

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
void ButtonLink::enterEvent(QEvent *event)
#else
void ButtonLink::enterEvent(QEnterEvent *event)
#endif
{
   Q_UNUSED(event);

   if (isEnabled())
   {
      QApplication::setOverrideCursor(Qt::PointingHandCursor);

      QFont f = font();
      f.setUnderline(true);
      setFont(f);
   }
}

void ButtonLink::leaveEvent(QEvent *event)
{
   Q_UNUSED(event);

   if (isEnabled())
   {
      QFont f = font();
      f.setUnderline(false);
      setFont(f);

      QApplication::restoreOverrideCursor();
   }
}
