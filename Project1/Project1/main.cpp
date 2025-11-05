#include <Windows.h>
#include"DX12.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:

        return 0;
    case WM_KEYDOWN:

        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(
    HINSTANCE hInstance,      // アプリケーションの識別番号
    HINSTANCE hPrevInstance,  // 基本使わなくていい
    LPSTR lpCmdLine,          // コマンドライン引数（起動時のオプション）
    int nCmdShow              // ウィンドウの表示方法（最大化、最小化など）
)
{
    DX12 dx12;
   
    //auto factory = dx12.CreateDXGIFactory();
    //auto adapter = dx12.GetHardwareAdapter(factory);
    //auto device = dx12.CreateD3D12Device(adapter);
    //auto commandQueue = dx12.CreateCommandQueue(device);
    //dx12.CreateSwapChain(factory, commandQueue, app.windowInstance_.handle_);


    // ここにメインの処理を書く
    // 1. ウィンドウクラス登録
    WNDCLASS wc{};
    wc.lpfnWndProc = WindowProc;         
    wc.hInstance = hInstance;            
    wc.lpszClassName = "GameWindow";     
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);  
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); 

    RegisterClass(&wc);


    // 2. ウィンドウ作成
    HWND hwnd = CreateWindow(
        "GameWindow",
        "My Game",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL, NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, nCmdShow);
    // 3. メッセージループ

    bool loop = true;
    
    while (loop)
    {
        MSG msg{};
        while (PeekMessage(&msg, NULL, 0, 0,PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            if (msg.message == WM_QUIT)
            {
                loop = false;
            }
        }
        if (loop == false)
        {
            break;
        }
    }

  

    return 0;
}

