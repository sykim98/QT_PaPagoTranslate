#include "translate.h"
#include "ui_translate.h"
#include <Qurl>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QJsonObject>

Translate::Translate(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Translate)
{
    ui->setupUi(this);
}

Translate::~Translate()
{
    delete ui;
}

void Translate::Init()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QUrl url("https://openapi.naver.com/v1/papago/n2mt");
    QNetworkRequest request(url);

    //QString clientId("yoiexLp1rXgF6VFt5BQq");
    //QString clientSecret("E41Lj1N0V");

    //QString krquery("안녕하세요.");

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("X-Naver-Client-Id", "YourClientId");
    request.setRawHeader("X-Naver-Client-Secret", "YourClientSecret");
    //request.setRawHeader("data:", "source=ko&target=en&text=만나서 반갑습니다.");


    QUrlQuery params;
    params.addQueryItem("query", "source=ko&target=en&text=만나서 반갑습니다.");

    manager->post(request, "source=ko&target=en&text=만나서 반갑습니다.");

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply* )));
    qDebug() << "Finished";
}


void Translate::replyFinished(QNetworkReply* reply)
{
    if (reply->error())
    {
        qDebug() << reply->error();
        return;
    }
    QJsonObject transString;
    qDebug() << reply->readLine();
}

void Translate::on_TrButton_clicked()
{

}


