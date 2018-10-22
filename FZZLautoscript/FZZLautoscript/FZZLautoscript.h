#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FZZLautoscript.h"

class FZZLautoscript : public QMainWindow {
  Q_OBJECT

public:
  FZZLautoscript(QWidget *parent = Q_NULLPTR);

private:
  Ui::FZZLautosciptClass ui;

private slots:
  void StartScript();
};
