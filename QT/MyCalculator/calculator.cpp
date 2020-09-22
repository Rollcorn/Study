#include "calculator.h"

#include <QGridLayout>
#include <QToolButton>
#include <QDebug>

Calculator::Calculator()
{
    m_display_up    = new QLineEdit();
    m_display_down  = new QLineEdit();
    m_sign          = new QLabel();
    QGridLayout* mainLayout = new QGridLayout;

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    m_display_up->setReadOnly(true);
    m_display_down->setReadOnly(true);

    m_display_up->setAlignment(Qt::AlignRight);
    m_display_down->setAlignment(Qt::AlignRight);

    m_display_up->setMaxLength(15);
    m_display_down->setMaxLength(15);

    QFont font = m_display_up->font();
    font.setPointSize(font.pointSize()+8);
    m_display_up->setFont(font);
    m_display_down->setFont(font);

    for(int i = 0; i < 10; ++i)
        m_digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));

    MyButton* pointButton   = createButton(".", SLOT(pointClicked()));
    MyButton* changeSignButton   = createButton(m_change_sign, SLOT(pointClicked()));

    MyButton* backspaceButton  = createButton("Backspace",SLOT(backspaceClicked()));
    MyButton* clearButton  = createButton("Clear",SLOT(clear()));
    MyButton* clearAllButton = createButton("Clear All",SLOT(clearAll()));

    MyButton* clearMemoryButton = createButton("MC",SLOT(clearMemory()));
    MyButton* readMemoryButton = createButton("MR",SLOT(readMemory()));
    MyButton* setMemoryButton = createButton("M+",SLOT(addToMemory()));
    MyButton* addToMemoryButton = createButton("M-",SLOT(minToMemory));

    MyButton* divisionButton = createButton(m_division_sign,SLOT(doubleOperandClicked()));
    MyButton* timesButton = createButton(m_times_sign,SLOT(doubleOperandClicked()));
    MyButton* minusButton = createButton(m_minus_sign,SLOT(doubleOperandClicked()));
    MyButton* plusButton = createButton(m_plus_sign,SLOT(doubleOperandClicked()));

    MyButton* squareRootButton = createButton(m_squareRoot_sign,SLOT(unaryOperatorCkicked()));
    MyButton* powerButton = createButton(m_power_sign,SLOT(unaryOperatorCkicked()));
    MyButton* reciprocalButton = createButton(m_reciprocal_sign,SLOT(unaryOperatorCkicked()));

    MyButton* equalButton = createButton("=",SLOT(equalClicked()));



    mainLayout->addWidget(m_display_up,     0, 0, 1, 6);
    mainLayout->addWidget(m_sign,           1, 5, 1, 1);
    mainLayout->addWidget(m_display_down,   2, 0, 1, 6);
    mainLayout->addWidget(backspaceButton, 3, 0,1 , 2);
    mainLayout->addWidget(clearButton, 3, 2, 1, 2);
    mainLayout->addWidget(clearAllButton, 3, 4, 1, 2);

    mainLayout->addWidget(clearMemoryButton, 4, 0);
    mainLayout->addWidget(readMemoryButton, 5, 0);
    mainLayout->addWidget(setMemoryButton, 6, 0);
    mainLayout->addWidget(addToMemoryButton, 7, 0);

    for (int i = 1; i < 10; ++i){
        int row = ((9 - i) / 3) + 4;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(m_digitButtons[i], row, column);
    }

    mainLayout->addWidget(m_digitButtons[0], 7, 1);
    mainLayout->addWidget(pointButton, 7, 2);
    mainLayout->addWidget(changeSignButton, 7, 3);

    mainLayout->addWidget(divisionButton, 4, 4);
    mainLayout->addWidget(timesButton, 5, 4);
    mainLayout->addWidget(minusButton, 6, 4);
    mainLayout->addWidget(plusButton, 7, 4);

    mainLayout->addWidget(squareRootButton, 4, 5);
    mainLayout->addWidget(powerButton, 5, 5);
    mainLayout->addWidget(reciprocalButton, 6, 5);
    mainLayout->addWidget(equalButton, 7, 5);

    setLayout(mainLayout);

    setWindowTitle("Calculator");

}

MyButton *Calculator::createButton(const QString &text, const char *member)
{
    MyButton* btn = new MyButton(text);
    connect(btn, SIGNAL(clicked()), this, member);
    return btn;
}
void Calculator::digitClicked(){

}
void Calculator::unaryOperatorClicked(){

}
void Calculator::doubleOperandClicked(){

}
void Calculator::equalClicked(){

}
void Calculator::pointClicked(){

}
void Calculator::changeSignClicked(){

}
void Calculator::backspaceClicked(){

}
void Calculator::clear(){

}
void Calculator::clearAll(){

}
void Calculator::clearMemory(){

}
void Calculator::readMemory(){

}
void Calculator::addToMemory(){

}
void Calculator::minToMemory(){

}
