#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
    ui->lineEdit->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    text += "1";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString text = ui->lineEdit->text();
    text += "2";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString text = ui->lineEdit->text();
    text += "3";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString text = ui->lineEdit->text();
    text += "4";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_5_clicked()
{
    QString text = ui->lineEdit->text();
    text += "5";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_6_clicked()
{
    QString text = ui->lineEdit->text();
    text += "6";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_7_clicked()
{
    QString text = ui->lineEdit->text();
    text += "7";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_8_clicked()
{
    QString text = ui->lineEdit->text();
    text += "8";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_9_clicked()
{
    QString text = ui->lineEdit->text();
    text += "9";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_10_clicked()
{
    QString text = ui->lineEdit->text();
    text += "0";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_11_clicked()
{
    QString text = ui->lineEdit->text();
    if (text != ""){
        int k = 0;
        foreach(QChar s, text){
            if (s == "."){
                k = 1;
            }
        }
        if (k == 0){
        text += ".";
        }
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}
void MainWindow::CheckSyst(bool &is_ok){
    QString val = ui->lineEdit->text();
    switch(flag_syst){
    case 0: {
        double dec = val.toDouble(&is_ok);
        if (is_ok){
            first = dec;
        }
        break;
    }
    case 1:{
        int hex = val.toInt(&is_ok, 16);
        if (is_ok){
            first = hex;
        }
        break;
    }
    case 2:{
        int bin = val.toInt(&is_ok, 2);
        if (is_ok){
            first = bin;
        }
        break;
    }
    case 3:{
        int oct = val.toInt(&is_ok, 8);
        if(is_ok){
            first = oct;
        }
        break;
    }
    }
}
void MainWindow::CheckRes(bool &is_ok){
    QString val = ui->lineEdit->text();
    switch(flag_syst){
    case 0: {
        double dec = val.toDouble(&is_ok);
        if (is_ok){
            second = dec;
        }
        break;
    }
    case 1:{
        int hex = val.toInt(&is_ok, 16);
        if (is_ok){
            second = hex;
        }
        break;
    }
    case 2:{
        int bin = val.toInt(&is_ok, 2);
        if (is_ok){
            second = bin;
        }
        break;
    }
    case 3:{
        int oct = val.toInt(&is_ok, 8);
        if(is_ok){
            second = oct;
        }
        break;
    }
    }
}
void MainWindow::MakeResult(){
    switch (flag_sign) {
    case 1:{
        result = first + second;
        break;
    }
    case 2:{result = first - second;
    break;
    }
    case 3:{result = first * second;
    break;
    }
    case 4:{result = first / second;
    break;
    }
    }

}
void MainWindow::on_pushButton_12_clicked()
{
    bool is_ok;
    CheckSyst(is_ok);
    if (is_ok){
    QString val = ui->lineEdit->text();
    flag_sign = 1;
    ui->label->setText(val + " + ");
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
    }else{
        ui->lineEdit->setText("");
        ui->label->setText("Error!");
        ui->lineEdit->setFocus();
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    bool is_ok;
    CheckSyst(is_ok);
    if (is_ok){
    QString val = ui->lineEdit->text();
    flag_sign = 2;
    ui->label->setText(val + " - ");
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
    }else{
        ui->lineEdit->setText("");
        ui->label->setText("Error!");
        ui->lineEdit->setFocus();
    }
}

void MainWindow::on_pushButton_14_clicked()
{
    bool is_ok;
    CheckSyst(is_ok);
    if (is_ok){
    QString val = ui->lineEdit->text();
    flag_sign = 3;
    ui->label->setText(val + " * ");
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
    }else{
        ui->lineEdit->setText("");
        ui->label->setText("Error!");
        ui->lineEdit->setFocus();
    }
}

void MainWindow::on_pushButton_15_clicked()
{
    bool is_ok;
    CheckSyst(is_ok);
    if (is_ok){
    QString val = ui->lineEdit->text();
    flag_sign = 4;
    ui->label->setText(val + " / ");
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
    }else{
        ui->lineEdit->setText("");
        ui->label->setText("Error!");
        ui->lineEdit->setFocus();
    }
}

void MainWindow::on_pushButton_16_clicked()
{
    QString val = ui->lineEdit->text();
    bool is_ok;
    if (first == 0 && second == 0){
        ui->lineEdit->setText(QString::number(0));
        ui->label->setText(QString::number(0));
        return;
    }
    CheckRes(is_ok);
    if (is_ok){
        MakeResult();
        switch (flag_syst) {
        case 0:{
            ui->lineEdit->setText(QString::number(result));
            QString lab = ui->label->text();
            lab += val;
            lab += " = ";
            lab += QString::number(result);
            ui->label->setText(lab);
            first = 0;
            second = 0;
            break;
        }
        case 1:{
            int res = int(result);
            QString test = QString::number(res, 16);
            QString lab = ui->label->text();
            lab += val;
            lab += " = ";
            lab += test;
            ui->label->setText(lab);
            ui->lineEdit->setText(test);
            first = 0;
            second = 0;
            break;
        }
        case 2:{
            int res = int(result);
            QString test = QString::number(res, 2);
            QString lab = ui->label->text();
            lab += val;
            lab += " = ";
            lab += test;
            ui->label->setText(lab);
            ui->lineEdit->setText(test);
            first = 0;
            second = 0;
            break;
        }
        case 3:{
            int res = int(result);
            QString test = QString::number(res, 8);
            QString lab = ui->label->text();
            lab += val;
            lab += " = ";
            lab += test;
            ui->label->setText(lab);
            ui->lineEdit->setText(test);
            first = 0;
            second = 0;
            break;
        }
        }
    }else{
        ui->lineEdit->setText("");
        ui->label->setText("Error!");
        ui->lineEdit->setFocus();
        first = 0;
        second = 0;
    }
}


void MainWindow::on_radioButton_toggled(bool checked)
{   if(checked){
        flag_syst = 0;
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->pushButton_17->setEnabled(false);
        ui->pushButton_18->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
        ui->pushButton_20->setEnabled(false);
        ui->pushButton_21->setEnabled(false);
        ui->pushButton_22->setEnabled(false);
    }
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    if (checked){
        flag_syst = 1;
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->pushButton_17->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_19->setEnabled(true);
        ui->pushButton_20->setEnabled(true);
        ui->pushButton_21->setEnabled(true);
        ui->pushButton_22->setEnabled(true);
    }
}

void MainWindow::on_radioButton_3_toggled(bool checked)
{
    if (checked){
        flag_syst = 2;
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(true);
        ui->pushButton_17->setEnabled(false);
        ui->pushButton_18->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
        ui->pushButton_20->setEnabled(false);
        ui->pushButton_21->setEnabled(false);
        ui->pushButton_22->setEnabled(false);
    }
}

void MainWindow::on_radioButton_4_toggled(bool checked)
{
    if (checked){
        flag_syst = 3;
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(true);
        ui->pushButton_17->setEnabled(false);
        ui->pushButton_18->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
        ui->pushButton_20->setEnabled(false);
        ui->pushButton_21->setEnabled(false);
        ui->pushButton_22->setEnabled(false);
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    QString text = ui->lineEdit->text();
    text += "A";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_18_clicked()
{
    QString text = ui->lineEdit->text();
    text += "B";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_19_clicked()
{
    QString text = ui->lineEdit->text();
    text += "C";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_20_clicked()
{
    QString text = ui->lineEdit->text();
    text += "D";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_21_clicked()
{
    QString text = ui->lineEdit->text();
    text += "E";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_22_clicked()
{
    QString text = ui->lineEdit->text();
    text += "F";
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus();
}
