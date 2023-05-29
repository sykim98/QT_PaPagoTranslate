#include "translate.h"
#include "qglobal.h"
#include "ui_translate.h"


Translate::Translate(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Translate)
    , manager(new QNetworkAccessManager(this))
    , request((QUrl)"https://openapi.naver.com/v1/papago/n2mt")
{
    ui->setupUi(this);
}

Translate::~Translate()
{
    delete ui;
    delete manager;
}

void Translate::Init()
{
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("X-Naver-Client-Id", "YOUR ClientId");
    request.setRawHeader("X-Naver-Client-Secret", "YOUR ClientSecret");
}


void Translate::replyFinished(QNetworkReply* reply)
{
    if (reply->error())
    {
        qDebug() << reply->error();
        return;
    }
    transOutput = reply->readAll();
    if (!transOutput.isEmpty())
    {
        QJsonDocument doc = QJsonDocument::fromJson(transOutput);
        QJsonObject obj = doc.object();
        QJsonObject obj2 = obj["message"].toObject();
        QJsonObject obj3 = obj2["result"].toObject();

        QJsonValue val = obj3.value("translatedText");

        transResult = val.toString();
    }
    qDebug() << transResult;
}

void Translate::on_TrButton_clicked()
{
    QString source = "ko";
    QString target = "en";
    QString prevText = ui->PrevText->toPlainText();
    QString strequest = "source="+source+"&target="+target+"&text="+prevText;

    manager->post(request, strequest.toStdString().c_str());

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply* )));
    ui->TransText->setPlainText(transResult);

    //connect(ui->TransText, SIGNAL(textChanged(transResult)), this, SLOT(changedText()));
}

/*
void Translate::changedText()
{
    qDebug()<<"Show";
    ui->TransText->show();
}
*/
