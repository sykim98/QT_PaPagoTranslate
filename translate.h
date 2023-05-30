#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QString>
#include <Qurl>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QTextEdit>

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
    QByteArray transOutput;
    QString transResult;
private slots:
    void on_TrButton_clicked();
    void replyFinished(QNetworkReply* reply);
    //void changedText();

    //void on_TransText_textChanged();
    void on_TransText_textChanged();

signals:
    void finished(QNetworkReply* reply);

private:
    Ui::Translate *ui;
    QNetworkAccessManager* manager;
    QNetworkRequest request;
    //QString transOutput;
};
#endif // TRANSLATE_H
