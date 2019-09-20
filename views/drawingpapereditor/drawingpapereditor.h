/*
 * @Name       QtDrawingPaperEditor
 * @Author    Robert Zhang
 * @E-mail    zhangzhiguo1207@163.com
 * @Date       2019-09-17
 */

#ifndef QTDRAWINGPAPEREDITOR_H
#define QTDRAWINGPAPEREDITOR_H

#include <QWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPoint>


class QtDrawingPaperEditor : public QWidget
{
    Q_OBJECT
public:
    explicit QtDrawingPaperEditor(QWidget *parent);
    ~QtDrawingPaperEditor() override;


protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    double CalcPaperWidthOfPerPixel(double scale_value,
                                                            int paper_width,
                                                            int widget_width);
    void UpdatePaperWidthOfPerPixel();
    void DrawPaper(QPainter &painter);

    int PaperWidth2DrawWidth(int paper_width);
    int DrawWidth2PaperWidth(int draw_width);
    void OnWheelValueChanged(QPoint mouse_pos, QPoint step);

    QPoint MousePoint2PaperPoint(QPoint point);
    void CentenThePaper();


private:
    QColor editor_bg_color_;
    QColor editor_paper_bg_color_;

    int paper_x_;
    int paper_y_;
    int paper_width_;
    int paper_height_;


    double scale_value_;
    double paper_width_of_per_pixel_;

    bool is_mouse_left_btn_down_;
    bool is_mouse_right_btn_down_;

    QPoint mouse_down_pos_;
    int orgin_dif_x_;
    int orgin_dif_y_;

    const double SCALE_VALUE_MAX = 20.0;
    const double SCALE_VALUE_MIN = 0.5;

    QRect draw_paper_rect_;

};

#endif // QTDRAWINGPAPEREDITOR_H
