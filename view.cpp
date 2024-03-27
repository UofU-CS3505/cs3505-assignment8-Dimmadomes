#include "view.h"
#include "ui_view.h"
#include "model.h"
#include "button.h"

View::View(Model &model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(60, 60, 60)");

    //Canvas Signals/Slots
    connect(ui->canvas, &Canvas::canvasClickSignal, &model, &Model::canvasClick);
    connect(&model, &Model::sendFrameToCanvas, ui->canvas, &Canvas::updateCanvas);
    connect(ui->canvas, &Canvas::canvasMoveSignal, &model, &Model::canvasMovement);

    //Update Color signal/slot
    connect(this, &View::colorValueChanged, &model, &Model::colorChanged);

    //RGBA Slider signals/slots
    connect(ui->redSlider, &QSlider::valueChanged, this, &View::redSliderValueChanged);
    connect(ui->greenSlider, &QSlider::valueChanged, this, &View::greenSliderValueChanged);
    connect(ui->blueSlider, &QSlider::valueChanged, this, &View::blueSliderValueChanged);
    connect(ui->alphaSlider, &QSlider::valueChanged, this, &View::alphaSliderValueChanged);

    //RGBA Spin box signals/slots
    connect(ui->redSpinBox, &QSpinBox::valueChanged, this, &View::redSpinBoxChanged);
    connect(ui->greenSpinBox, &QSpinBox::valueChanged, this, &View::greenSpinBoxChanged);
    connect(ui->blueSpinBox, &QSpinBox::valueChanged, this, &View::blueSpinBoxChanged);
    connect(ui->alphaSpinBox, &QSpinBox::valueChanged, this, &View::alphaSpinBoxChanged);

}

View::~View()
{
    delete ui;
}

void View::redSliderValueChanged(){
    ui->redSpinBox->setValue(ui->redSlider->value());
    emit colorValueChanged("red", ui->redSlider->value());
}

void View::greenSliderValueChanged(){
    ui->greenSpinBox->setValue(ui->greenSlider->value());
    emit colorValueChanged("green", ui->greenSlider->value());
}

void View::blueSliderValueChanged(){
    ui->blueSpinBox->setValue(ui->blueSlider->value());
    emit colorValueChanged("blue", ui->blueSlider->value());
}

void View::alphaSliderValueChanged(){
    ui->alphaSpinBox->setValue(ui->alphaSlider->value());
    emit colorValueChanged("alpha", ui->alphaSlider->value());
}

void View::redSpinBoxChanged(){
    ui->redSlider->setValue(ui->redSpinBox->value());
    emit colorValueChanged("red", ui->redSpinBox->value());
}

void View::greenSpinBoxChanged(){
    ui->greenSlider->setValue(ui->greenSpinBox->value());
    emit colorValueChanged("green", ui->greenSpinBox->value());
}

void View::blueSpinBoxChanged(){
    ui->blueSlider->setValue(ui->blueSpinBox->value());
    emit colorValueChanged("blue", ui->blueSpinBox->value());
}

void View::alphaSpinBoxChanged(){
    ui->alphaSlider->setValue(ui->alphaSpinBox->value());
    emit colorValueChanged("alpha", ui->alphaSpinBox->value());
}
