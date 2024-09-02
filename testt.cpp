#include <windows.h>

// 窗口过程函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY: // 当窗口被销毁时，发送退出消息，退出消息循环
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 定义窗口类
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc; // 窗口过程函数
    wc.hInstance = hInstance; // 实例句柄
    wc.lpszClassName = L"WindowClass"; // 类名

    // 注册窗口类
    RegisterClass(&wc);

    // 创建窗口
    HWND hwnd = CreateWindowEx(
        0,
        L"WindowClass", // 类名
        L"My Window",   // 窗口标题
        WS_OVERLAPPEDWINDOW, // 窗口样式
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, // 窗口位置和大小
        NULL, NULL, hInstance, NULL);

    // 如果创建窗口失败，返回错误
    if (hwnd == NULL) {
        return 0;
    }

    // 显示窗口
    ShowWindow(hwnd, nCmdShow);

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}