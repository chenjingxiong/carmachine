#include "musiclisttable.h"

#include <QHeaderView>
#include <QScrollBar>
#include "global_value.h"

musicListTable::musicListTable(QWidget *parent):QTableWidget(parent)
{
    init();
    connect(this,SIGNAL(cellEntered(int,int)),this,SLOT(slot_cellClicked(int,int)));
}

void musicListTable::init()
{
    setMouseTracking(true);
    setFrameShadow(QFrame::Plain);
    setFrameShape(QFrame::NoFrame);
    setFocusPolicy(Qt::NoFocus);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //   setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//垂直scrollbar禁用
    setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Expanding);
    setShowGrid(false);       //隐藏线
    this->horizontalHeader()->setVisible(false);
    this->verticalHeader()->setVisible(false);
    setEditTriggers(QTableWidget::NoEditTriggers);  // 设置表格不可编辑
    setSelectionBehavior (QAbstractItemView::SelectRows); //设置点击选取行
    setSelectionMode (QAbstractItemView::SingleSelection);
    setContextMenuPolicy(Qt::CustomContextMenu);
    setAcceptDrops(true);

    horizontalHeader()->setVisible(false);
    verticalHeader()->setVisible(false);

    insertColumn(0);
    insertColumn(1);
    insertColumn(2);
    insertColumn(3);
    verticalHeader()->setDefaultSectionSize(60);//设置默认item高度

    verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;margin: 0px 2px 0px 0px;}"
                                       "QScrollBar::handle{background:rgb(217,217,217);border-radius:4px;}"
                                       "QScrollBar::handle:hover{background: rgb(191,191,191);}"
                                       "QScrollBar::add-line:vertical{border:1px rgb(230,230,230);height: 1px;}"
                                       "QScrollBar::sub-line:vertical{border:1px rgb(230,230,230);height: 1px;}"
                                       "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background:transparent;}");

    setStyleSheet("QTableWidget{color:rgb(48,48,48);}"
                  "QTableWidget::item:selected{background:rgb(180,180,180,100);}"
                  "QTableWidget::item{selection-color:rgb(37,120,255);}");
    setFont(QFont(Font_Family,Font_size_Normal,QFont::Normal));

}


void musicListTable::setRowTextColor(int row, const QColor &color)const
{
    for(int col=1; col<columnCount()-1; col++)
    {
        QTableWidgetItem *it = item(row, col);
        it->setTextColor(color);
    }
}

void musicListTable::slot_cellClicked(int, int)
{


}






