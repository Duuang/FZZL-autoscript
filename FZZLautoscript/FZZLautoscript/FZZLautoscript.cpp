#include "FZZLautoscript.h"
#include "Stage.h"

#include <thread>

FZZLautoscript::FZZLautoscript(QWidget *parent)
    : QMainWindow(parent) {
  ui.setupUi(this);
  connect(ui.startbutton, SIGNAL(clicked()), this, SLOT(StartScript()));
}
void a();
void FZZLautoscript::StartScript() {
  Stage currentstage("3-04", 0, 1, 1);
  
  std::thread thread_autoplay(&Stage::StartPlay, currentstage);
  thread_autoplay.detach();
}

