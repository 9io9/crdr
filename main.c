#include <windows.h>
#ifdef ENABLE_PRINT
#include <stdio.h>
#else
#define fprintf(...)
#endif
#include <math.h>

#include "shapes/shapes.h"

LRESULT CALLBACK WindowMsgHandler(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps;

            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint,  (HBRUSH) (COLOR_WINDOW + 1));

            Vertex2D tri[3] = {
                {.x = 10.0f, .y = 15.0f},
                {.x = 100.0f, .y = 120.0f},
                {.x = 20.0f, .y = 170.0f}
            };

            RECT client_rect;

            GetClientRect(hwnd, &client_rect);

            int client_width = client_rect.right - client_rect.left;
            int client_height = client_rect.bottom - client_rect.top;

            fprintf(stdout, "client_width: %d, client_height: %d\n", client_width, client_height);

            switch (RenderPaintPure2DTriangle(tri, RGB(0, 0, 0), hdc, client_width, client_height)) {
                case RDRPAINT_SUC:
                    fprintf(stdout, "triangle paint success\n");
                break;
                default:
                    fprintf(stdout, "triangle paint fail\n");
                break;
            }

            EndPaint(hwnd, &ps);

            return 0;
        }

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    WNDCLASS wc = { 0 };

    wc.lpfnWndProc = WindowMsgHandler;
    wc.hInstance = hInstance;
    wc.lpszClassName = "RenderClass";

    RegisterClass(&wc);

    int wnd_x, wnd_y;
    int wnd_width, wnd_height;
    int screen_width, screen_height;

    screen_width = GetSystemMetrics(SM_CXSCREEN);
    screen_height = GetSystemMetrics(SM_CYSCREEN);

    wnd_x = screen_width / 2;
    wnd_y = screen_height / 2;

    wnd_width = 200;
    wnd_height = 200;

    HWND hwnd = CreateWindowEx(
        0,
        "RenderClass",
        "CRender",
        WS_OVERLAPPEDWINDOW,
        wnd_x,
        wnd_y,
        wnd_width, wnd_height,
        NULL, NULL,
        hInstance, NULL
        );

    ShowWindow(hwnd, nShowCmd);

    UpdateWindow(hwnd);

    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}