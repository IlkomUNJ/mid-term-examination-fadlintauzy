#include "drawingcanvas.h"

CustomMatrix createVerticalDetector(int size) {
    bool pattern[10][10] = {false};
    int center1 = (size / 2) - 1;
    int center2 = size / 2;
    for (int r = 0; r < size; r++) {
        pattern[r][center1] = true;
        pattern[r][center2] = true;
    }
    return CustomMatrix(pattern);
}

CustomMatrix createHorizontalDetector(int size) {
    bool pattern[10][10] = {false};
    int center1 = (size / 2) - 1;
    int center2 = size / 2;
    for (int c = 0; c < size; c++) {
        pattern[center1][c] = true;
        pattern[center2][c] = true;
    }
    return CustomMatrix(pattern);
}

CustomMatrix createThickDotDetector(int size, int dot_size = 3) {
    bool pattern[10][10] = {false};
    int start = (size / 2) - (dot_size / 2);
    int end = start + dot_size - 1;

    for (int r = start; r <= end; r++) {
        for (int c = start; c <= end; c++) {
            if (r >= 0 && r < size && c >= 0 && c < size) {
                pattern[r][c] = true;
            }
        }
    }
    return CustomMatrix(pattern);
}

DrawingCanvas::DrawingCanvas(QWidget *parent)  {
    // Set a minimum size for the canvas
    setMinimumSize(this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
    // Set a solid background color
    setStyleSheet("background-color: white; border: 1px solid gray;");
}

void DrawingCanvas::clearPoints(){
    m_points.clear();
    // Trigger a repaint to clear the canvas
    update();
}

void DrawingCanvas::paintLines(){
    /* Todo
     * Implement lines drawing per even pair
    */

    isPaintLinesClicked = true;
    update();
}

void DrawingCanvas::segmentDetection(){
    QPixmap pixmap = this->grab();
    QImage image = pixmap.toImage();

    int width = image.width();
    int height = image.height();
    const int WINDOW_SIZE = 10; // New window size

    vector<CustomMatrix> windows;

    for(int i = 0; i < width - WINDOW_SIZE; i++){
        for(int j = 0; j < height - WINDOW_SIZE; j++){

            bool local_window[WINDOW_SIZE][WINDOW_SIZE] = {false};

            for(int m = 0; m < WINDOW_SIZE; m++){
                for(int n = 0; n < WINDOW_SIZE; n++){
                    QRgb rgbValue = image.pixel(i + m, j + n);

                    local_window[m][n] = (rgbValue != 0xffffffff);
                }
            }

            CustomMatrix mat(local_window);

            windows.push_back(mat);
        }
    }
    return;
}

void DrawingCanvas::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set up the pen and brush for drawing the points
    QPen pen(Qt::blue, 5);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::blue));

    // Draw a small circle at each stored point
    for (const QPoint& point : std::as_const(m_points)) {
        painter.drawEllipse(point, 3, 3);
    }

    if(isPaintLinesClicked){
        cout << "paint lines block is called" << endl;
        pen.setColor(Qt::red);
        pen.setWidth(4); // 4-pixel wide line
        pen.setStyle(Qt::SolidLine);
        painter.setPen(pen);

        // Set the painter's pen to our custom pen.
        painter.setPen(pen);

        for(int i=0;i<m_points.size()-1;i+=2){
            //cout << m_points[i].x() << endl;
            painter.drawLine(m_points[i], m_points[i+1]);
        }
        isPaintLinesClicked = false;

        //return painter pen to blue
        pen.setColor(Qt::blue);
        painter.setPen(pen);
    }
}

void DrawingCanvas::mousePressEvent(QMouseEvent *event) {
    // Add the mouse click position to our vector of points
    m_points.append(event->pos());
    // Trigger a repaint
    update();
}


