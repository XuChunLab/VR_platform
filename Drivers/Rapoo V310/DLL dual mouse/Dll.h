#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

// 此类是从 Dll.dll 导出的
class DLL_API CDll {
public:
	CDll(void);
	// TODO: 在此添加您的方法。
};

extern DLL_API int nDll;

// 鼠标数据结构体
typedef struct _DLL_MOUSE_DATA_ {
	FLOAT fdX;			// 鼠标1在X方向移动的距离。单位：微米
	FLOAT fdY;			// 鼠标2在Y方向移动的距离。单位：微米
	FLOAT fdR;			// 鼠标1沿赤道移动的距离。单位：微米
	FLOAT fdR2;			// 鼠标2沿赤道移动的距离。单位：微米
	UINT32 ndT;			// 鼠标移动的时间，单位：μs
} DLL_MOUSE_DATA, *PDLL_MOUSE_DATA;

// ---------------------------------------------------------------
// 	函 数 名: SearchMouse
// 	功能说明: 关闭当前使用的鼠标，然后搜索可以使用的鼠标，并打开
// 				这些鼠标。搜索结果应该是两个。
//	形    参: pnMouseNum - 指向鼠标数量变量指针，用于取得计算机上
//				安装的滚球鼠标数量
//	返 回 值:	=TRUE, 表示执行成功
//				=FALSE, 表示执行失败，pnMouseNum内数据无效。
// ---------------------------------------------------------------
DLL_API BOOL __stdcall SearchMouse(OUT PINT32 pnMouseNum);

// ---------------------------------------------------------------
// 	函 数 名: QueryMouse
// 	功能说明: 查询可以使用的鼠标数量。查询结果应该是两个。
//	形    参: pnMouseNum - 指向鼠标数量变量指针，用于取得计算机上
//				安装的滚球鼠标数量
//	返 回 值:	=TRUE, 表示执行成功
//				=FALSE, 表示执行失败，pnMouseNum内数据无效。
// ---------------------------------------------------------------
DLL_API BOOL __stdcall QueryMouse(OUT PINT32 pnMouseNum);

// ---------------------------------------------------------------
// 	函 数 名: CleanupMouseData
// 	功能说明: 清除已有的鼠标活动记录。
//	形    参: 无
//	返 回 值:	=TRUE, 表示执行成功
//				=FALSE, 表示执行失败
// ---------------------------------------------------------------
DLL_API BOOL __stdcall CleanupMouseData(void);

// ---------------------------------------------------------------
// 	函 数 名: AsyncGetMouse
// 	功能说明: 异步方式读取鼠标数据。本函数执行后会立即返回。
//	形    参: pMouseData - 鼠标数据结构体指针，用于取回鼠标数据
//	返 回 值:	=TRUE, 表示成功读取数据；
//				=FALSE, 表示读取数据失败，pMouseData内数据无效。
// ---------------------------------------------------------------
DLL_API BOOL __stdcall AsyncGetMouse(OUT PDLL_MOUSE_DATA pMouseData);

// ---------------------------------------------------------------
// 	函 数 名: SyncGetMouse
// 	功能说明: 同步方式读取鼠标数据。本函数执行后即阻塞，直至鼠标
// 				活动（数据有效），或者5 ms超时，或者发生错误后才返回。
//	形    参: pMouseData - 鼠标数据结构体指针，用于取回鼠标数据
//	返 回 值:	=TRUE, 表示成功读取数据；
//				=FALSE, 表示超时或者读取数据失败，pMouseData内数据无效。
// ---------------------------------------------------------------
DLL_API BOOL __stdcall SyncGetMouse(OUT PDLL_MOUSE_DATA pMouseData);
