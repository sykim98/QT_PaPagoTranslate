#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <QMainWindow>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class Translate; }
QT_END_NAMESPACE

class Translate : public QMainWindow
{
    Q_OBJECT

public:
    Translate(QWidget *parent = nullptr);
    ~Translate();

public:
    void Init();

private slots:
    void on_TrButton_clicked();
    void replyFinished(QNetworkReply* reply);

private:
    Ui::Translate *ui;

};
#endif // TRANSLATE_H
