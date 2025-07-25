#include "ClickableFrame.h"

#include <QLabel>
#include <QMouseEvent>
#include <QStyle>
#include <QVBoxLayout>

ClickableFrame::ClickableFrame(QWidget *parent)
   : QFrame(parent)
{
   setAttribute(Qt::WA_DeleteOnClose);
}

ClickableFrame::ClickableFrame(const QString &text, Qt::Alignment alignment, QWidget *parent)
   : QFrame(parent)
{
   const auto layout = new QVBoxLayout(this);
   layout->setContentsMargins(2, 2, 2, 2);
   layout->setSpacing(0);
   layout->addWidget(mText = new QLabel(text));
   layout->setAlignment(alignment);

   mText->setTextFormat(Qt::RichText);
}

void ClickableFrame::mousePressEvent(QMouseEvent *e)
{
   mPressed = rect().contains(e->pos()) && e->button() == Qt::LeftButton;

   QFrame::mousePressEvent(e);
}

void ClickableFrame::mouseReleaseEvent(QMouseEvent *e)
{
   if (mPressed && rect().contains(e->pos()) && e->button() == Qt::LeftButton)
      emit clicked();

   QFrame::mouseReleaseEvent(e);
}

void ClickableFrame::enterEvent(QEnterEvent *event)
{
   if (mHasLinkStyles)
   {
      QFont f = mText->font();
      f.setUnderline(true);
      mText->setFont(f);
   }

   QFrame::enterEvent(event);
}

void ClickableFrame::leaveEvent(QEvent *event)
{
   if (mHasLinkStyles)
   {
      QFont f = mText->font();
      f.setUnderline(false);
      mText->setFont(f);
   }

   QFrame::leaveEvent(event);
}
