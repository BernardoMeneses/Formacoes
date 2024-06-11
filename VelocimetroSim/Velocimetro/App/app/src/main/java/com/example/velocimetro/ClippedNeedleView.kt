package com.example.velocimetro

import android.content.Context
import android.graphics.Canvas
import android.graphics.Color
import android.graphics.Paint
import android.graphics.Path
import android.util.AttributeSet
import android.view.View

class ClippedNeedleView @JvmOverloads constructor(
    context: Context, attrs: AttributeSet? = null, defStyleAttr: Int = 0
) : View(context, attrs, defStyleAttr) {

    private var angle: Float = 0f
    private val greenPaint = Paint().apply { color = Color.parseColor("#008000") }
    private val yellowPaint = Paint().apply { color = Color.YELLOW }
    private val redPaint = Paint().apply { color = Color.RED }
    private val orangePaint = Paint().apply {color = Color.parseColor("#FFA500")}
    private val LightGreenPaint = Paint().apply {color = Color.GREEN}
    private val needlePaint = Paint().apply { color = Color.BLACK; strokeWidth = 5f }
    private val path = Path()

    fun setAngle(angle: Float) {
        this.angle = angle
        invalidate()
    }

    override fun onDraw(canvas: Canvas) {
        super.onDraw(canvas)

        val centerX = width / 2f
        val centerY = height / 2f
        val radius = Math.min(centerX, centerY)

        if (angle > 0) {
            drawSegment(canvas, centerX, centerY, radius, 0f, Math.min(angle, 20f), LightGreenPaint)
        }
        if (angle > 20) {
            drawSegment(canvas, centerX, centerY, radius, 20f, Math.min(angle, 80f) - 20f, greenPaint)
        }
        if (angle > 80) {
            drawSegment(canvas, centerX, centerY, radius, 80f, Math.min(angle, 120f) - 80f, yellowPaint)
        }
        if (angle > 120) {
            drawSegment(canvas, centerX, centerY, radius, 120f, Math.min(angle, 160f) - 120f, orangePaint)
        }
        if (angle > 160) {
            drawSegment(canvas, centerX, centerY, radius, 160f, angle - 160f, redPaint)
        }

        // Desenhe a linha da agulha
        val needleAngle = Math.toRadians((angle - 90).toDouble())
        val needleX = (centerX + radius * Math.cos(needleAngle)).toFloat()
        val needleY = (centerY + radius * Math.sin(needleAngle)).toFloat()

        canvas.drawLine(centerX, centerY, needleX, needleY, needlePaint)

        // Desenhe o contorno do velocímetro
        drawArc(canvas, centerX, centerY, radius, 0f, 180f, Paint().apply { color = Color.BLACK; style = Paint.Style.STROKE; strokeWidth = 5f })
    }

    private fun drawSegment(canvas: Canvas, cx: Float, cy: Float, radius: Float, startAngle: Float, sweepAngle: Float, paint: Paint) {
        path.reset()
        path.moveTo(cx, cy)
        path.arcTo(
            cx - radius, cy - radius,
            cx + radius, cy + radius,
            startAngle - 90, sweepAngle, true
        )
        path.lineTo(cx, cy)
        path.close()
        canvas.drawPath(path, paint)
    }

    private fun drawArc(canvas: Canvas, cx: Float, cy: Float, radius: Float, startAngle: Float, sweepAngle: Float, paint: Paint) {
        path.reset()
        path.arcTo(
            cx - radius, cy - radius,
            cx + radius, cy + radius,
            startAngle - 90, sweepAngle, true
        )
        canvas.drawPath(path, paint)
    }
}







