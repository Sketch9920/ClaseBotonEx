
#pragma once
#include <Windows.h>
#include <string>
#include <commctrl.h>

#if!defined DWLSetLayeredFunc 
 #define DWLSetLayeredFunc 
 #pragma comment(lib, "msimg32.lib")  // Libreria del AlphaBlend y Gradientill
#endif


#if!defined DWL_CENTRADO
 #define DWL_CENTRADO
 #define CENTRADO -99
#endif

#if !defined DWL_GGET
 #define DWL_GGET
 #define GGET_X_LPARAM(lp)   ((int)(short)LOWORD(lp))
 #define GGET_Y_LPARAM(lp)   ((int)(short)HIWORD(lp))
#endif



//#if defined Dev_Windows_Lib
// namespace DWL {
//#endif


#define DWL_BOTONEX_CLICK_IZQUIERDO WM_USER + 200
#define DWL_BOTONEX_CLICK_DERECHO   WM_USER + 201
#define DWL_BOTONEX_CLICK_MEDIO     WM_USER + 202

class ColoresClaseBotonEx {
public :		// Miembros publicos
				//
				// Constructor por defecto
				// ColoresClaseBotonEx(void);
				ColoresClaseBotonEx(void) {
					
				};
				//
				// Constructor asignador de colores
				// ColoresClaseBotonEx(COLORREF nGradient1, COLORREF nGradient2, COLORREF nGradientHilight, COLORREF nTextoNormal, COLORREF nTextoHilight, COLORREF nTextoDesactivado, COLORREF nFondoVentanaPadre, COLORREF nBorde);
				ColoresClaseBotonEx(COLORREF nGradient1, COLORREF nGradient2, COLORREF nGradientHilight, COLORREF nTextoNormal, COLORREF nTextoHilight, COLORREF nTextoDesactivado, COLORREF nFondoVentanaPadre, COLORREF nBorde) {
					Gradient1 = nGradient1; 
					Gradient2 = nGradient2; 
					GradientHilight = nGradientHilight; 
					TextoNormal = nTextoNormal; 
					TextoHilight = nTextoHilight;
					TextoDesactivado = nTextoDesactivado;
					FondoVentanaPadre = nFondoVentanaPadre; 
					Borde = nBorde; 
				};
				//
				// Destructor
				// ~ColoresClaseBotonEx(void);
		       ~ColoresClaseBotonEx(void) { 
			    };
				// 
				// Color para la parte de arriba del degradado
 COLORREF		Gradient1;
				// 
				// Color para la parte de abajo del degradado
 COLORREF		Gradient2;
				// 
				// Color para el degradado resaltado
 COLORREF		GradientHilight; 
				//
				// Color del texto normal
 COLORREF		TextoNormal;
				//
				// Color del texto resaltado
 COLORREF		TextoHilight;
				//
				// Color del texto desactivado / presionado
 COLORREF		TextoDesactivado;
				//
				// Color del fondo de la ventana padre
 COLORREF		FondoVentanaPadre;
				//
				// Color del borde del boton
 COLORREF		Borde;
};              //
////////////////// Final ColoresClaseBotonEx


class FuentesClaseBotonEx {
public : ///////// Miembros publicos
				//
				// Constructor por defecto
				// FuentesClaseBotonEx(void);
				FuentesClaseBotonEx(void) { 
				};
				//
				// Contructor asignador de fuentes
				// FuentesClaseBotonEx(HFONT nFuenteNormal, HFONT nFuenteSubrayada);
				FuentesClaseBotonEx(HFONT nFuenteNormal, HFONT nFuenteSubrayada) {
					FuenteNormal = nFuenteNormal; 
					FuenteSubrayada = nFuenteSubrayada; 
				};
				//
				// Destructor
				// ~FuentesClaseBotonEx(void);
			   ~FuentesClaseBotonEx(void) { 
			    };
				// 
			    // Fuente normal
 HFONT			FuenteNormal;
				//
				// Fuente resaltada
 HFONT			FuenteSubrayada;
};				//
////////////////// Final FuentesClaseBotonEx

//#if defined Dev_Windows_Lib

//class ClaseBotonEx : public ClaseVentana {

//#else

 /*class BotonExThunk {
  public:
                           BotonExThunk(void) { };
                          ~BotonExThunk(void) { };
 protected :
  virtual LRESULT CALLBACK WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
  DWORD                    InitThunk(void *pThis)                                 { *(DWORD*)(_thunk + 0) = 0x042444C7;  *(DWORD*)(_thunk + 4) = (DWORD)pThis;  *(BYTE*) (_thunk + 8) = 0xe9;  *(DWORD*)(_thunk + 9) = **(DWORD**)this - ((int)_thunk + 13);  return (DWORD) _thunk; };
 private:
  char                    _thunk[13];
 };*/



class ClaseBotonEx {
// #endif
public: ////////////////////////// Miembros publicos
								//
								// Constructor
								// ClaseBotonEx(void);
								ClaseBotonEx(void);
								//
								// Destructor
								// ~ClaseBotonEx(void);
							   ~ClaseBotonEx(void);
							    //
							    // Funcion para crear el boton especificando los colores
							    // void	Crear(HWND hWndParent, const char *nTxt, const int cX, const int cY, const int cAncho, const int cAlto, const int ID, COLORREF nGradient1, COLORREF nGradient2, COLORREF nGradientHilight, COLORREF nTextoNormal, COLORREF nTextoHilight, COLORREF nTextoDesactivado, COLORREF nBorde);
 void							Crear(HWND hWndParent, const char *nTxt, const int cX, const int cY, const int cAncho, const int cAlto, HMENU ID, COLORREF nGradient1, COLORREF nGradient2, COLORREF nGradientHilight, COLORREF nTextoNormal, COLORREF nTextoHilight, COLORREF nTextoDesactivado, COLORREF nBorde);
								//
								// Funcion para crear el boton especificando las Clases ColoresClaseBotonEx y FuentesClaseBotonEx
								// void	Crear(HWND hWndParent, const char *nTxt, const int cX, const int cY, const int cAncho, const int cAlto, const int ID, ColoresClaseBotonEx *Colores = NULL, FuentesClaseBotonEx *Fuentes = NULL);
 void							Crear(HWND hWndParent, const char *nTxt, const int cX, const int cY, const int cAncho, const int cAlto, HMENU ID, ColoresClaseBotonEx *Colores = NULL, FuentesClaseBotonEx *Fuentes = NULL);
								//
								// Funcion para repintar el boton
								// void RePintar(const bool Forzar = false);
 void							RePintar(const bool Forzar = false);
								// 
								// Funcion para activar / desactivar el boton
                                // void Activado(const bool Activar);
 void							Activado(const bool Activar);
								//
								// Funcion para marcar el boton
								// inline void Marcado(const bool Marcar);
 inline void					Marcado(const bool Marcar) { 
									_Checked = Marcar; 
									RePintar(); 
								};
								//
								// Funcion que retorna si el boton esta marcado o no
								// inline const bool Marcado(void); 
 inline const bool				Marcado(void) {
									 return _Checked; 
								};
								//
								// Funcion para mostrar / ocultar el boton
								// void Visible(const bool Show);
 void                           Visible(const bool Show);
								//
								// Funcion para asignar el texto del boton
								// inline void Texto(const char *Txt);
 inline void                    Texto(const char *Txt) {
									_Texto = Txt; 
									RePintar(); 
								};
								//
								// Funcion que retorna el texto del boton
								// inline const char *Texto(void);
 inline const char             *Texto(void) {
									return _Texto.c_str(); 
								};
								//
								// Funcion que recibe el mensaje WM_PAINT del windowprocedure
								// virtual void OnPaint(HDC hDC);
 virtual void					OnPaint(HDC hDC);
								//
								// Funcion que pinta todo el boton cuando su estado es normal
								// virtual void OnEstadoNormalPaint(HDC hDC, RECT *Espacio);
 virtual void                   OnEstadoNormalPaint(HDC hDC, RECT *Espacio);
								//
								// Funcion que pinta todo el boton cuando su estado es resaltado
								// virtual void OnEstadoHilightPaint(HDC hDC, RECT *Espacio);
 virtual void                   OnEstadoHilightPaint(HDC hDC, RECT *Espacio);
								//
								// Funcion que pinta todo el boton cuando su estado es presionado
								// virtual void OnEstadoPresionadoPaint(HDC hDC, RECT *Espacio);
 virtual void                   OnEstadoPresionadoPaint(HDC hDC, RECT *Espacio);
								//
								// Funcion que pinta todo el boton cuando su estado es desactivado
								// virtual void OnEstadoDesactivadoPaint(HDC hDC, RECT *Espacio);
 virtual void                   OnEstadoDesactivadoPaint(HDC hDC, RECT *Espacio);
								//
								// Funcion para pintar mas cosas una vez pintada la base del boton (Esta funcion es Perfecta para pintar iconos en el boton)
								// virtual void OnPostPaint(HDC hDC);
 virtual void                   OnPostPaint(HDC hDC) { 
								};
protected : ////////////////////// Miembros protegidos
								//
								// Funcion que recibe cuando se suelta un boton del mouse
								// virtual void	OnMouseUp(const int Button, const int cX, const int cY, WPARAM wParam);
 virtual void					OnMouseUp(const int Button, const int cX, const int cY, WPARAM wParam);
								//
								// Funcion que recibe cuando se presiona un boton del mouse
								// virtual void	OnMouseDown(const int Button, const int cX, const int cY, WPARAM wParam);
 virtual void					OnMouseDown(const int Button, const int cX, const int cY, WPARAM wParam);
								//
								// Funcion que recibe cuando el mouse se mueve dentro del control
								// virtual void	OnMouseMove(const int cX, const int cY, WPARAM wParam);
 virtual void					OnMouseMove(const int cX, const int cY, WPARAM wParam);
								//
								// Funcion que recibe cuando el mouse no esta dentro del control (Se activa con TrackMouseEvent)
								// void	OnMouseLeave(void);
 void							OnMouseLeave(void);
								//
								// Funcion que borra los objetos GDI de la memoria
								// void _BorrarMemoria(void);
 void                          _BorrarMemoria(void);
								// 
								// Funcion que pinta el degradado del fondo
								// void _PintarGradient(HDC hDC, COLORREF Col1, COLORREF Col2);
 void		          	 	   _PintarGradient(HDC hDC, COLORREF Col1, COLORREF Col2);
								//
								// Funcion que pinta el borde del boton
								// inline void _EnmarcarBoton(HDC hDC);
 inline void                   _EnmarcarBoton(HDC hDC);
								//
								// Estado del boton
 int                           _Estado;
								//
								// Ultimo estado del boton
 int                           _PEstado;
								//
								// El boton esta presionado
 bool                          _Presionado;
								//
								// Texto del boton
 std::string                   _Texto;
								//
								// ID del boton
 HMENU                          _ID;
								//
								// Flag para TrackMouseEvent
 bool                          _MouseLeave;
								//
								// Flag que determina si los colores los ha creado este control o son externos
 bool                          _ColoresPropios;
								//
								// Flag que determina si las fuentes las ha creado este control o son externas
 bool                          _FuentesPropias;
								//
								// El boton esta marcado
 bool                          _Checked;
								//
 								// Colores del boton
 ColoresClaseBotonEx          *_Colores;
								//
								// Fuentes del boton
 FuentesClaseBotonEx		  *_Fuentes;
								//
								// WindowProcedure para el boton
								// LRESULT CALLBACK	WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam); 
 /*LRESULT CALLBACK	*/
 static LRESULT CALLBACK WndProc(HWND dhWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
 /////////////////////////////////
// #if !defined Dev_Windows_Lib   ///////////////////////////////////////////////////////////////////////////
 // Parte de la ClaseVentana para la clase independiente                                                 //
 //////////////////////////////////////////////////////////////////////////////////////////////////////////
 public : //////////////////////// Miembros publicos de la ClaseVentana
								//
                                // Funcion para asignar esta clase a un control ya creado (Se usa normalmente para USERCONTROLS en los Dialogos)
                                // void Asignar(const int ID_Control, HWND hWndParent);
  void                          Asignar(const int ID_Control, HWND hWndParent) {
									_hWnd = GetDlgItem(hWndParent, ID_Control); 
									// Conectar();
								};
								//
                                // Funcion para crear la Ventana
                                // void CrearVentana(HWND Parent, const char *Nombre, UINT Estilo, const char *Text, const int cX, const int cY, const int cAncho, const int cAlto, HMENU Menu, DWORD EstiloExtendido = NULL, HBRUSH ColorFondo = NULL, const char *cIko = NULL);
  void                          CrearVentana(HWND Parent, const char *Nombre, UINT Estilo, const char *Text, const int cX, const int cY, const int cAncho, const int cAlto, HMENU Menu, DWORD EstiloExtendido = NULL, HBRUSH ColorFondo = NULL, const char *cIko = NULL) {
									RegistrarClase(Nombre, ColorFondo, cIko);
									int NX = cX;
									int NY = cY;
									if (cX == CENTRADO) NX = _CalcularCentrado(Parent, true, cAncho);
									if (cY == CENTRADO) NY = _CalcularCentrado(Parent, false, cAlto);
									_hWnd = CreateWindowEx(EstiloExtendido, Nombre, Text, Estilo, NX, NY, cAncho, cAlto, Parent, Menu, GetModuleHandle(NULL), NULL);
									
									// *** Para 32 o 64 bits *****
									SetWindowLongPtr(_hWnd, GWLP_USERDATA, (LONG_PTR)this);
									// ***************************

									// Conectar();  .. Inecesario
								};
 protected : /////////////////////
								//
								// Registra la Clase Ventana
								// void RegistrarClase(const char *Nombre, HBRUSH ColorFondo, const char *cIko);
  void			                RegistrarClase(const char *Nombre, HBRUSH ColorFondo, const char *cIko) { 
									////WNDCLASSEX WndClass; 
									////WndClass.cbSize = sizeof(WNDCLASSEX);
									////WndClass.style = 0; 
									////WndClass.lpfnWndProc = (WNDPROC)WndProc;  //(WNDPROC)_PrimerMensaje; 
									////WndClass.cbClsExtra = 0; 
									////WndClass.cbWndExtra = 0; 
									////WndClass.hInstance = GetModuleHandle(NULL); 
									////if (cIko != NULL) { 
									////	WndClass.hIcon = LoadIcon(GetModuleHandle(NULL), cIko); 
									////	WndClass.hIconSm = LoadIcon(GetModuleHandle(NULL), cIko); 
									////} 
									////else {
									////	WndClass.hIcon = LoadIcon(GetModuleHandle(NULL), IDI_APPLICATION);
									////	WndClass.hIconSm = LoadIcon(GetModuleHandle(NULL), IDI_APPLICATION); 
									////}
									////WndClass.hCursor = LoadCursor (0, IDC_ARROW); 
									////if (ColorFondo != NULL) { 
									////	WndClass.hbrBackground = ColorFondo; 
									////} 
									////else {
									////	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
									////} 
									////WndClass.lpszMenuName = 0; 
									////WndClass.lpszClassName = Nombre; 
									////WndClass.hIconSm = NULL;
									  WNDCLASSEX WndClass;
									  WndClass.cbSize = sizeof(WNDCLASSEX);
									  WndClass.style = CS_HREDRAW | CS_VREDRAW;//CS_CLASSDC;;
									  WndClass.lpfnWndProc = (WNDPROC)WndProc;
									  WndClass.cbClsExtra = 0;
									  WndClass.cbWndExtra = 0;
									  WndClass.hInstance = GetModuleHandle(NULL);
									  WndClass.hIcon = NULL;
									  WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
									  WndClass.hbrBackground = 0;// CreateSolidBrush(RGB(0, 0, 255));
									  WndClass.lpszMenuName = NULL;//MAKEINTRESOURCE(IDR_MENU1);
									  WndClass.lpszClassName = Nombre;
									  WndClass.hIconSm = NULL;

									HRESULT h = RegisterClassEx (&WndClass); 
								};
 private : /////////////////////// -Declaraciones privadas
								//
								// Funcion que conecta esta clase con la ventana
								// void Conectar(void);

  //void			                Conectar(void) { 
		//							DWORD dw = InitThunk(this); 
		//							SetWindowLong(_hWnd, GWL_WNDPROC, dw); 
		//						};
								//
							    // Primer mensaje que se mandara desde la ventana
								// static LRESULT CALLBACK _PrimerMensaje(HWND dhWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { return DefWindowProc(dhWnd, uMsg, wParam, lParam); };

  //static LRESULT CALLBACK	   _PrimerMensaje(HWND dhWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)      { 
		//							return DefWindowProc(dhWnd, uMsg, wParam, lParam); 
		//						};

 								///////////////////////////////////////////////
 ///////////////////////////////// Base ventana para la clase independiente //
                                /////////////////////////////////////////////
 public : //////////////////////// Miembros publicos
								//
								// Funcion para Mostrar / Ocultar la ventana
					            // virtual void Visible(const bool Show);
 /*virtual void				    Visible(const bool Show) { 
									ShowWindow(_hWnd, (Show == true) ? SW_SHOW : SW_HIDE); 
								}; 
								//	*/
								// Funcion que retorna si la ventana esta Visible
								// const BOOL Visible();
 const BOOL						Visible(void) {
									return static_cast<BOOL>(IsWindowVisible(_hWnd)); 
								};
								/*//	
								// Funcion para Activar / Desactivar la ventana
								// inline  Activado(const bool Enable);
 inline void			        Activado(const bool Activar) {
									EnableWindow(_hWnd, Activar); 
								};*/
								//	
								// Funcion que retorna si la ventana esta Activada
								// const BOOL Activado();
 const BOOL						Activado(void) {
									return static_cast<BOOL>(IsWindowEnabled(_hWnd)); 
			                    };
								//	
								// Funcion para Asignar el Foco a la ventana
								// virtual void AsignarFoco(void);
 virtual void					AsignarFoco(void) {
									SetFocus(_hWnd); 
								};
								//	
								// Funcion que retorna el Handle de la ventana
						        // inline HWND hWnd(void);
 inline HWND					hWnd(void) { 
									return _hWnd;
								};
								//	
								// Funcion para asignar la posicion X de la ventana
								// inline void X(const int Pos);
 inline void					X(const int Pos) {
									RECT R;
									GetWindowRect(_hWnd, &R);
									int Alt = 0;
									if (GetWindowLong(_hWnd, GWL_STYLE) & WS_CAPTION) Alt = GetSystemMetrics(SM_CYCAPTION);
									MoveWindow(_hWnd, Pos, R.top, R.right, R.bottom + Alt, false); 
								};
								//	
								// Funcion para asignar el Ancho de la ventana
								// inline void Ancho(const int Pos);
 inline void					Ancho(const int Pos) {
									RECT R; 
									GetWindowRect(_hWnd, &R); 
									int Alt = 0; 
									if (GetWindowLong(_hWnd, GWL_STYLE) & WS_CAPTION) Alt = GetSystemMetrics(SM_CYCAPTION); 
									MoveWindow(_hWnd, R.left, R.top, Pos, R.bottom + Alt, false); 
								};
								//	
								// Funcion para asignar la posicion Y de la ventana
								// inline void Y(const int Pos);
 inline void					Y(const int Pos) {
									RECT R;
									GetWindowRect(_hWnd, &R); 
									int Alt = 0; 
									if (GetWindowLong(_hWnd, GWL_STYLE) & WS_CAPTION) Alt = GetSystemMetrics(SM_CYCAPTION); 
									MoveWindow(_hWnd, R.left, Pos, R.right, R.bottom + Alt, false);
								};
								//	
								// Funcion para asignar la Altura de la ventana
					            // inline void Alto(const int Pos);
 inline void				    Alto(const int Pos) {
									RECT R; 
									GetWindowRect(_hWnd, &R); 
									int Alt = 0; 
									if (GetWindowLong(_hWnd, GWL_STYLE) & WS_CAPTION) Alt = GetSystemMetrics(SM_CYCAPTION); 
									MoveWindow(_hWnd, R.left, R.top, R.right, Alt + Pos, false); 
								};
								//	
								// Funcion que retorna la X de la ventana
								// inline const int X(void);
 inline const int				X(void) {
									WINDOWPLACEMENT WP;
									WP.length = sizeof(WINDOWPLACEMENT); 
									GetWindowPlacement(_hWnd, &WP); 
									return WP.rcNormalPosition.left; 
								};
								//	
								// Funcion que retorna el Ancho de la ventana
								// inline const int Ancho(void);
 inline const int				Ancho(void) {
									WINDOWPLACEMENT WP;
									WP.length = sizeof(WINDOWPLACEMENT);
									GetWindowPlacement(_hWnd, &WP); 
									return WP.rcNormalPosition.right - WP.rcNormalPosition.left; 
								};
								//	
								// Funcion que retorna la Y de la ventana
								// inline const int Y(void);
 inline const int				Y(void) {
									WINDOWPLACEMENT WP; 
									WP.length = sizeof(WINDOWPLACEMENT); 
									GetWindowPlacement(_hWnd, &WP); 
									return WP.rcNormalPosition.top; 
								}; 
								//	
								// Funcion que retorna la Altura de la ventana
								// inline const int Alto(void);
 inline const int				Alto(void) { 
									WINDOWPLACEMENT WP;
									WP.length = sizeof(WINDOWPLACEMENT); 
									GetWindowPlacement(_hWnd, &WP);
									return WP.rcNormalPosition.bottom - WP.rcNormalPosition.top; 
								};
								//	
								// Funcion para mover la ventana
								// inline void Move(const int X, const int Y, const int Anchura, const int Altura);
 inline void					Mover(const int cX, const int cY, const int Anchura, const int Altura) { 
									int Alt = 0;
									if (GetWindowLong(_hWnd, GWL_STYLE) & WS_CAPTION) Alt = GetSystemMetrics(SM_CYCAPTION);
									MoveWindow(_hWnd, cX, cY, Anchura, Altura + Alt, false);
								};
								//	
								// Funcion para Crear un timer en la ventana
								// inline void CrearTimer(const int cID, const int Milisegundos);
 inline void					CrearTimer(const unsigned int nID, const unsigned int MiliSegundos) { 
									SetTimer(_hWnd, nID, MiliSegundos, NULL);
								};
								//	
								// Funcion para Eliminar un timer en la ventana
								// inline void EliminarTimer(const int cID);
 inline void					EliminarTimer(const unsigned int nID) { 
									KillTimer(_hWnd, nID); 
								};
								//	
								// Funcion para destruir la ventana y liberar toda la memoria relacionada con ella
								// virtual void Destruir(void);
 virtual void					Destruir(void) { 
									if (DestroyWindow(_hWnd) != 0) _hWnd = NULL; 
								};
								//	
								// Funcion para hacer Translucida la ventana
								// void Translucido(const int Nivel);
 inline void					Translucido (const BYTE Nivel) { 
									BOOL (WINAPI *fSetLayeredWindowAttributes)(HWND hwnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags);
									HMODULE hUser32 = GetModuleHandle("USER32.DLL"); 
									SetWindowLong(_hWnd, GWL_EXSTYLE, 0x00080000 | WS_EX_TOPMOST | WS_EX_TOOLWINDOW); 
									fSetLayeredWindowAttributes = (BOOL (WINAPI *)(HWND hwnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags))GetProcAddress(hUser32, "SetLayeredWindowAttributes");
									if (fSetLayeredWindowAttributes != NULL) fSetLayeredWindowAttributes(_hWnd, NULL, Nivel, 0x00000002); 
								};
								//	
								// Funcion que retorna la ID de esta ventana
								// const int ID(void);
 inline const int				ID(void) {
									return static_cast<int>(GetWindowLong(_hWnd, GWL_ID)); 
								};
protected : ////////////////////// Miembros protegidos
								//
								// Funcion para calcular la X o la Y de la ventana quando esta necesita ser centrada
								// inline const int _CalcularCentrado(HWND chWndParent, const bool cAncho, const int cValor);
 inline const int			   _CalcularCentrado(HWND chWndParent, const bool cAncho, const int cValor) { 
									RECT RectParent;
									if (chWndParent != NULL) { 
										GetClientRect(chWndParent, &RectParent);
										if (cAncho == true) return static_cast<int>((RectParent.right - cValor) / 2); 
										else 				return static_cast<int>((RectParent.bottom - cValor) / 2);
									}
									else {
										if (cAncho == true)	return static_cast<int>((GetSystemMetrics(SM_CXSIZE) - cValor) /2);  
										else				return static_cast<int>((GetSystemMetrics(SM_CYSIZE) - cValor) /2); 
									} 
								};
								//
								// Handle de la ventana
 HWND				           _hWnd;
//#endif							//
};

//#if defined Dev_Windows_Lib
//}
//#endif



// Version 0.72
// -Se ha cambiado la forma de mirar si el mouse esta encima del control o no
// 	 Antes se hacia con un SetCapture.. haora se usa TrackMouseEvent , y luego reservo SetCapture para cuando se pulsa el mouse solo
//   De esta forma al estar encima del boton no estara capturado y podras usar las teclas del sistema.
// -La distribucion del codigo ha cambiado de forma que sea mas facil editar tanto la clase independiente como la normal
// -Tambien se han comentado todas las funciones en el header


