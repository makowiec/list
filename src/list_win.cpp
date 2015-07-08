//============================================================================
// Name        : list.cpp
// Author      : Makowiec
// Version     : 0.1
// Copyright   : IC
// Description : Program do tworzenia listy plików wersja okienkowa, Ansi-style
//				 Pliki mniejsze ni¿ 1TB
//============================================================================

#include <windows.h>

LPCSTR NazwaKlasy = "Klasa Okienka";
MSG Komunikat;

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

    // WYPE£NIANIE STRUKTURY
    WNDCLASSEX wc;

    wc.cbSize = sizeof( WNDCLASSEX );
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );

    // REJESTROWANIE KLASY OKNA
    if( !RegisterClassEx( & wc ) )
    {
        MessageBox( NULL, "Wysoka Komisja odmawia rejestracji tego okna!", "Niestety...",
        MB_ICONEXCLAMATION | MB_OK );
        return 1;
    }

    // TWORZENIE OKNA
    HWND hwnd;

    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "KC List", WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL );

    if( hwnd == NULL )
    {
        MessageBox( NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION );
        return 1;
    }

    ShowWindow( hwnd, nCmdShow ); // Poka¿ okienko...
    UpdateWindow( hwnd );

    // Pêtla komunikatów
    while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }
    return Komunikat.wParam;
}

// OBS£UGA ZDARZEÑ
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
    case WM_CLOSE:
        DestroyWindow( hwnd );
        break;

    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;

        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }

    return 0;
}
