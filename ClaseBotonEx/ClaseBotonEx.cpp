
#include "clasebotonex.h"

//#if defined Dev_Windows_Lib
// namespace DWL {
//#endif

ClaseBotonEx::ClaseBotonEx(void) {
	_hWnd = NULL;
	_FuentesPropias = false;
	_ColoresPropios = false;
}


ClaseBotonEx::~ClaseBotonEx(void) {
	_BorrarMemoria();
}


void ClaseBotonEx::_BorrarMemoria(void) {
	if (_ColoresPropios == true) delete _Colores;
	if (_FuentesPropias == true) {
		 DeleteObject(_Fuentes->FuenteNormal);
		 DeleteObject(_Fuentes->FuenteSubrayada);
		 delete _Fuentes;
	}
	_Colores = NULL;
	_Fuentes = NULL;
}

void ClaseBotonEx::Crear(HWND hWndParent, const char *nTxt, const int cX, const int cY, const int cAncho, const int cAlto, HMENU cID, ColoresClaseBotonEx *Colores, FuentesClaseBotonEx *Fuentes) {
	_BorrarMemoria();
	CrearVentana(hWndParent, "Dev_Lib_ClaseBotonEx", WS_CHILD, nTxt, cX, cY, cAncho, cAlto, cID);
	_Texto = nTxt;
	_ID = cID;
	_Estado = 0; 
	_PEstado = -1;
	_Presionado = false;
	_Checked = false;
 
	if (Colores == NULL) {
		_ColoresPropios = true;
		_Colores = new ColoresClaseBotonEx;
		_Colores->Gradient1 = RGB(192, 192, 192);
		_Colores->Gradient2 = RGB(128, 128, 128);
		_Colores->GradientHilight = RGB(210, 210, 210);
		_Colores->TextoDesactivado = RGB(192, 192, 192);
		_Colores->TextoHilight = RGB(255, 255, 0);
		_Colores->TextoNormal = RGB(255, 255, 255);
		HWND hWndParent = GetParent(_hWnd);
		HDC  hDCParent  = GetDC(hWndParent);
		_Colores->FondoVentanaPadre = GetBkColor(hDCParent);
		ReleaseDC(hWndParent, hDCParent);
	}
	else {
		_ColoresPropios = false;
		_Colores = Colores;
	}

	if (Fuentes == NULL) {
		_FuentesPropias = true;
		_Fuentes = new FuentesClaseBotonEx;
		_Fuentes->FuenteNormal = CreateFont(13, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, FF_ROMAN, "Tahoma");
		_Fuentes->FuenteSubrayada = CreateFont(13, 0, 0, 0, FW_NORMAL, 0, true, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, FF_ROMAN, "Tahoma"); 
	}
	else {
		_FuentesPropias = false;
		_Fuentes = Fuentes;
	}
	_MouseLeave = false;
} 


void ClaseBotonEx::Crear(HWND hWndParent, const char *nTxt, const int cX, const int cY, const int cAncho, const int cAlto, HMENU cID, COLORREF nGradient1, COLORREF nGradient2, COLORREF nGradientHilight, COLORREF nTextoNormal, COLORREF nTextoHilight, COLORREF nTextoDesactivado, COLORREF nBorde) {
	_BorrarMemoria();
	CrearVentana(hWndParent, "Dev_Lib_ClaseBotonEx",  WS_CHILD, nTxt, cX, cY, cAncho, cAlto, cID);
	_Texto = nTxt;
	_ID = cID;
	_Estado = 0; 
	_PEstado = -1;
	_Presionado = false;
	_Checked = false;
	
	_ColoresPropios = true;
	_Colores = new ColoresClaseBotonEx;
	_Colores->Gradient1 = nGradient1;
	_Colores->Gradient2 = nGradient2;
	_Colores->GradientHilight = nGradientHilight;
	_Colores->TextoDesactivado = nTextoDesactivado;
	_Colores->TextoHilight = nTextoHilight;
	_Colores->TextoNormal = nTextoNormal;
	_Colores->Borde = nBorde;
	HWND hWndParent2 = GetParent(_hWnd);
	HDC  hDCParent  = GetDC(hWndParent2);
	_Colores->FondoVentanaPadre = GetBkColor(hDCParent);
	ReleaseDC(hWndParent2, hDCParent);

	_FuentesPropias = true;
	_Fuentes->FuenteNormal = CreateFont(13, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, FF_ROMAN, "Tahoma");
	_Fuentes->FuenteSubrayada = CreateFont(13, 0, 0, 0, FW_NORMAL, 0, true, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, FF_ROMAN, "Tahoma"); 
}



void ClaseBotonEx::Activado(const bool Activar) {
	if (Activar == false) _Estado = 3;
	else                  _Estado = 0;
	_PEstado = -1;
	_Presionado = false;
	EnableWindow(_hWnd, Activar);
	RePintar();
}


void ClaseBotonEx::OnMouseDown(const int Button, const int cX, const int cY, WPARAM wParam) {
	SetCapture(_hWnd);
	_Presionado = true;
	_Estado = 2;
	RePintar();
}


void ClaseBotonEx::OnMouseUp(const int Button, const int cX, const int cY, WPARAM wParam) {
	ReleaseCapture();
	RECT  RC;
	POINT Pt = { cX, cY };
	GetClientRect(_hWnd, &RC);
	if (PtInRect(&RC, Pt) != 0) {
		//PostMessage(GetParent(_hWnd), DWL_BOTONEX_CLICK_IZQUIERDO + Button, (WPARAM)_ID, (LPARAM)_hWnd);
		PostMessage(GetParent(_hWnd), WM_COMMAND, (WPARAM)_ID, (LPARAM)0);
		_Estado = 1;
	}
	else {
		_Estado = 0;
	}	
	_Presionado = false;
	
	RePintar();
}


void ClaseBotonEx::OnMouseLeave(void) {
	_MouseLeave = false;
	_Estado = 0;
	RePintar();
}

void ClaseBotonEx::OnMouseMove(const int cX, const int cY, WPARAM wParam) {
	if (_MouseLeave == false) {
		TRACKMOUSEEVENT Trk;
		Trk.cbSize = sizeof(TRACKMOUSEEVENT);
		Trk.dwFlags = TME_LEAVE;
		Trk.hwndTrack = _hWnd;
		TrackMouseEvent(&Trk);
		_MouseLeave = true;
	}
/*	if (GetCapture() != _hWnd) {
		SetCapture(_hWnd);
		_Estado = 1;
	}*/
	//else { // _Capturado == true
		RECT  RC;
		POINT Pt = { cX, cY };
		GetClientRect(_hWnd, &RC);
		if (PtInRect(&RC, Pt) != 0) { // Si esta dentro*/
			if (_Presionado == false) {     _Estado = 1;   }
			else { /* Presionado == true */ _Estado = 2;   }
		}
		else { // Esta fuera
		//	if (_Presionado == false) ReleaseCapture(); 
			_Estado = 0;
		}
//	}
	//if (MP3App::ToolTip.Visible() == TRUE) MP3App::ToolTip.Visible(FALSE);

	RePintar();
}


void ClaseBotonEx::Visible(const bool Show) {
	if (Show == true) {
		ShowWindow(_hWnd, SW_SHOW);
		if (IsWindowEnabled(_hWnd) == TRUE) _Estado = 0;
		else                                _Estado = 3;
		_PEstado = -1;  
		RePintar();
	}
	else {
		 ShowWindow(_hWnd, SW_HIDE);
		_Estado = -1; 
	}
}



void ClaseBotonEx::RePintar(const bool Forzar) {
	if (Forzar == false) {
		if (_PEstado == _Estado) return;
	}
	_PEstado = _Estado;
	HDC hDC = GetDC(_hWnd);
	OnPaint(hDC);
	ReleaseDC(_hWnd, hDC);
}



void ClaseBotonEx::_EnmarcarBoton(HDC hDC) {
	RECT   RC;
	HBRUSH ColorBorde = CreateSolidBrush(_Colores->Borde);
	GetClientRect(_hWnd, &RC);
	FrameRect(hDC, &RC, ColorBorde);
	SetPixel(hDC, 0, 0, _Colores->FondoVentanaPadre);
	SetPixel(hDC, 0, RC.bottom -1, _Colores->FondoVentanaPadre);
	SetPixel(hDC, RC.right -1, 0, _Colores->FondoVentanaPadre);
	SetPixel(hDC, RC.right -1, RC.bottom -1, _Colores->FondoVentanaPadre);
	DeleteObject(ColorBorde);
}



void ClaseBotonEx::_PintarGradient(HDC hDC, COLORREF Col1, COLORREF Col2) {
	RECT          RC;
	TRIVERTEX     GCVertex[2]; 
	GRADIENT_RECT tGRect; 
	GetClientRect(_hWnd, &RC);
	RC.left ++;  RC.right--; RC.top++; RC.bottom--;
	GCVertex[0].Red = (unsigned short)((Col1 & 0xFF) * 0x100); 
	GCVertex[0].Green = (unsigned short)(Col1 & 0xFF00);
	GCVertex[0].Blue = (unsigned short)((Col1 & 0xFF0000) / 0x100); 
	GCVertex[0].x = RC.left; GCVertex[0].y = RC.top; 
	GCVertex[1].Red = (unsigned short)((Col2 & 0xFF) * 0x100); 
	GCVertex[1].Green = (unsigned short)(Col2 & 0xFF00); 
	GCVertex[1].Blue = (unsigned short)((Col2 & 0xFF0000) / 0x100); 
	GCVertex[1].x = RC.right; 
	GCVertex[1].y = RC.bottom; 
	tGRect.UpperLeft = 0;  
	tGRect.LowerRight = 1; 
	GradientFill(hDC, GCVertex, 2, &tGRect, 1, GRADIENT_FILL_RECT_V);  
}



void ClaseBotonEx::OnPaint(HDC hDC) {
	if (_hWnd == NULL) return;
	HFONT VFuente = NULL;
	RECT  RC;
	GetClientRect(_hWnd, &RC);
	RC.left ++;  RC.right--; RC.top++; RC.bottom--;
	SetBkMode(hDC, TRANSPARENT);
	_EnmarcarBoton(hDC);
	switch (_Estado) {
		case 0 :	OnEstadoNormalPaint(hDC, &RC);			break;
		case 1 :	OnEstadoHilightPaint(hDC, &RC);			break;
		case 2 : 	OnEstadoPresionadoPaint(hDC, &RC);		break;
		case 3 :	OnEstadoDesactivadoPaint(hDC, &RC);		break;
	}
	OnPostPaint(hDC);
}


void ClaseBotonEx::OnEstadoNormalPaint(HDC hDC, RECT *Espacio) {
	HFONT VFuente = (HFONT) SelectObject(hDC, _Fuentes->FuenteNormal);
	SetTextColor(hDC, _Colores->TextoNormal);
	if (_Checked == false) {
		_PintarGradient(hDC, _Colores->Gradient1, _Colores->Gradient2);
		DrawText(hDC, _Texto.c_str(), (int)_Texto.size(), Espacio, DT_CENTER);
	}
	else {
		_PintarGradient(hDC, _Colores->Gradient2, _Colores->Gradient1);
		Espacio->left ++; Espacio->top ++; Espacio->right ++; Espacio->bottom ++;
		DrawText(hDC, _Texto.c_str(), (int)_Texto.size(), Espacio, DT_CENTER);
	}	
	SelectObject(hDC, VFuente);
}


void ClaseBotonEx::OnEstadoHilightPaint(HDC hDC, RECT *Espacio) {
	HFONT VFuente = (HFONT) SelectObject(hDC, _Fuentes->FuenteSubrayada);
	SetTextColor(hDC, _Colores->TextoHilight);
	if (_Checked == false) {
		_PintarGradient(hDC, _Colores->GradientHilight, _Colores->Gradient2);
		DrawText(hDC, _Texto.c_str(), (int)_Texto.size(), Espacio, DT_CENTER);
	}
	else {
		_PintarGradient(hDC, _Colores->Gradient2, _Colores->GradientHilight);
		Espacio->left ++; Espacio->top ++; Espacio->right ++; Espacio->bottom ++;
		DrawText(hDC, _Texto.c_str(), (int)_Texto.size(), Espacio, DT_CENTER);
	}
	SelectObject(hDC, VFuente);
}


void ClaseBotonEx::OnEstadoPresionadoPaint(HDC hDC, RECT *Espacio) {
	HFONT VFuente = (HFONT) SelectObject(hDC, _Fuentes->FuenteSubrayada);
	SetTextColor(hDC, _Colores->TextoHilight);
	_PintarGradient(hDC, _Colores->Gradient2, _Colores->Gradient1);
	Espacio->left ++; Espacio->top ++; Espacio->right ++; Espacio->bottom ++;
	DrawText(hDC, _Texto.c_str(), (int)_Texto.size(), Espacio, DT_CENTER);
	SelectObject(hDC, VFuente);
}


void ClaseBotonEx::OnEstadoDesactivadoPaint(HDC hDC, RECT *Espacio) {
	HFONT VFuente = (HFONT) SelectObject(hDC, _Fuentes->FuenteNormal);
	SetTextColor(hDC, _Colores->TextoDesactivado);
	_PintarGradient(hDC, _Colores->Gradient1, _Colores->Gradient2);
	DrawText(hDC, _Texto.c_str(), (int)_Texto.size(), Espacio, DT_CENTER);
	SelectObject(hDC, VFuente);
}



LRESULT CALLBACK ClaseBotonEx::WndProc(HWND dhWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ClaseBotonEx *pDButton = (ClaseBotonEx *)GetWindowLongPtr(dhWnd, GWLP_USERDATA);
	
	switch (uMsg)
	{
		case WM_MOUSEMOVE   :  pDButton->OnMouseMove(GGET_X_LPARAM(lParam), GGET_Y_LPARAM(lParam), wParam);																				break;
		case WM_LBUTTONDOWN :  pDButton->OnMouseDown(0, GGET_X_LPARAM(lParam), GGET_Y_LPARAM(lParam), wParam);																			break;
		case WM_RBUTTONDOWN :  pDButton->OnMouseDown(1, GGET_X_LPARAM(lParam), GGET_Y_LPARAM(lParam), wParam);																			break;
		case WM_MBUTTONDOWN :  pDButton->OnMouseDown(2, GGET_X_LPARAM(lParam), GGET_Y_LPARAM(lParam), wParam);																			break;
		case WM_LBUTTONUP   :  pDButton->OnMouseUp(0, GGET_X_LPARAM(lParam), GGET_Y_LPARAM(lParam), wParam);																			break;	
		case WM_RBUTTONUP   :  pDButton->OnMouseUp(1, GGET_X_LPARAM(lParam), GGET_Y_LPARAM(lParam), wParam);																			break;
		case WM_MBUTTONUP   :  pDButton->OnMouseUp(2, GGET_X_LPARAM(lParam), GGET_Y_LPARAM(lParam), wParam);																			break;
//		case WM_KEYDOWN     :  this->OnKeyDown(static_cast<int>(wParam), lParam);																									break;
		case WM_ERASEBKGND  :  return 1;																																			break;
		case WM_MOUSELEAVE  :  pDButton->OnMouseLeave();																																		break;
		case WM_PAINT       :  HDC DC; PAINTSTRUCT ps; DC = BeginPaint(pDButton->_hWnd, &ps); pDButton->OnPaint(DC); EndPaint(pDButton->_hWnd, &ps);														break;
	}

	return DefWindowProc(dhWnd, uMsg, wParam, lParam);
	//return DefWindowProc(_hWnd, uMsg, wParam, lParam);
}



//#if defined Dev_Windows_Lib
// }
//#endif
