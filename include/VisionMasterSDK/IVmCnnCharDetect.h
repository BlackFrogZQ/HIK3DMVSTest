/***************************************************************************************************
 * File：IVmCnnCharDetect.h
 * Note：CH: DL字符定位模块接口声明 | En: Interface for the CnnCharDetect tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CNNCHARDETECT_H_
#define _IVM_CNNCHARDETECT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCnnCharDetectModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 目标排序 | EN: Sort Object
        typedef enum _SortObjectModeEnum
        {
            // CH: 按中心点X坐标排序 | EN: Sort by X Coordinate of Center
            SortObjectMode_XCoordinate = 0x1,

            // CH: 按中心点Y坐标排序 | EN: Sort by Y Coordinate of Center
            SortObjectMode_YCoordinate = 0x2,

            // CH: 按置信度排序 | EN: Sort by Confidence
            SortObjectMode_Confidence = 0x3,

        }SortObjectModeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class CnnCharDetectRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the CnnCharDetectParams.  */
        class CnnCharDetectParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnCharDetectParams() {}
            virtual ~CnnCharDetectParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual CnnCharDetectRoiManager* GetModuRoiManager() = 0;

            // CH: 模型文件路径 | EN: Model File Path
            __declspec(property(put = SetLoadModelPath, get = GetLoadModelPath)) const char* LoadModelPath;

            virtual const char* GetLoadModelPath() = 0;

            virtual void SetLoadModelPath(const char* value) = 0;

            // CH: 方案存模型 | EN: Save Model Data
            __declspec(property(put = SetSaveModelDataEnable, get = GetSaveModelDataEnable)) bool SaveModelDataEnable;

            virtual bool GetSaveModelDataEnable() = 0;

            virtual void SetSaveModelDataEnable(bool value) = 0;

            // CH: 最大查找个数 | EN: Max Number to Find
            __declspec(property(put = SetMaxObjNum, get = GetMaxObjNum)) int MaxObjNum;

            virtual int GetMaxObjNum() = 0;

            virtual void SetMaxObjNum(int value) = 0;

            // CH: 最小置信度 | EN: Min Confidence
            __declspec(property(put = SetMinScore, get = GetMinScore)) double MinScore;

            virtual double GetMinScore() = 0;

            virtual void SetMinScore(double value) = 0;

            // CH: 最小平均分数 | EN: Min Box Score
            __declspec(property(put = SetBoxScore, get = GetBoxScore)) double BoxScore;

            virtual double GetBoxScore() = 0;

            virtual void SetBoxScore(double value) = 0;

            // CH: 最大重叠率 | EN: Overlap Threshold
            __declspec(property(put = SetMaxOverlap, get = GetMaxOverlap)) double MaxOverlap;

            virtual double GetMaxOverlap() = 0;

            virtual void SetMaxOverlap(double value) = 0;

            // CH: 链接阈值 | EN: Link Threshold
            __declspec(property(put = SetLinkThreshold, get = GetLinkThreshold)) double LinkThreshold;

            virtual double GetLinkThreshold() = 0;

            virtual void SetLinkThreshold(double value) = 0;

            // CH: 目标排序 | EN: Sort Object
            __declspec(property(put = SetSortObjectMode, get = GetSortObjectMode)) SortObjectModeEnum SortObjectMode;

            virtual SortObjectModeEnum GetSortObjectMode() = 0;

            virtual void SetSortObjectMode(SortObjectModeEnum value) = 0;

            // CH: 边缘筛选使能 | EN: Edge Filter Enable
            __declspec(property(put = SetOutRoiFilterEnable, get = GetOutRoiFilterEnable)) bool OutRoiFilterEnable;

            virtual bool GetOutRoiFilterEnable() = 0;

            virtual void SetOutRoiFilterEnable(bool value) = 0;

            // CH: 最小边缘分数 | EN: Min Edge Score
            __declspec(property(put = SetMinEdgeScore, get = GetMinEdgeScore)) double MinEdgeScore;

            virtual double GetMinEdgeScore() = 0;

            virtual void SetMinEdgeScore(double value) = 0;

            // CH: 字符角度使能 | EN: Character Angle Enable
            __declspec(property(put = SetAngleEnable, get = GetAngleEnable)) bool AngleEnable;

            virtual bool GetAngleEnable() = 0;

            virtual void SetAngleEnable(bool value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetStartAngle, get = GetStartAngle)) int StartAngle;

            virtual int GetStartAngle() = 0;

            virtual void SetStartAngle(int value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetEndAngle, get = GetEndAngle)) int EndAngle;

            virtual int GetEndAngle() = 0;

            virtual void SetEndAngle(int value) = 0;

            // CH: 字符宽度使能 | EN: Character Width Enable
            __declspec(property(put = SetWidthEnable, get = GetWidthEnable)) bool WidthEnable;

            virtual bool GetWidthEnable() = 0;

            virtual void SetWidthEnable(bool value) = 0;

            // CH: 宽度范围 | EN: Width Range
            __declspec(property(put = SetMinWidth, get = GetMinWidth)) int MinWidth;

            virtual int GetMinWidth() = 0;

            virtual void SetMinWidth(int value) = 0;

            // CH: 宽度范围 | EN: Width Range
            __declspec(property(put = SetMaxWidth, get = GetMaxWidth)) int MaxWidth;

            virtual int GetMaxWidth() = 0;

            virtual void SetMaxWidth(int value) = 0;

            // CH: 字符高度使能 | EN: Character Height Enable
            __declspec(property(put = SetHeightEnable, get = GetHeightEnable)) bool HeightEnable;

            virtual bool GetHeightEnable() = 0;

            virtual void SetHeightEnable(bool value) = 0;

            // CH: 高度范围 | EN: Height Range
            __declspec(property(put = SetMinHeight, get = GetMinHeight)) int MinHeight;

            virtual int GetMinHeight() = 0;

            virtual void SetMinHeight(int value) = 0;

            // CH: 高度范围 | EN: Height Range
            __declspec(property(put = SetMaxHeight, get = GetMaxHeight)) int MaxHeight;

            virtual int GetMaxHeight() = 0;

            virtual void SetMaxHeight(int value) = 0;

            // CH: 个数判断 | EN: Number Check
            __declspec(property(put = SetNumLimitEnable, get = GetNumLimitEnable)) bool NumLimitEnable;

            virtual bool GetNumLimitEnable() = 0;

            virtual void SetNumLimitEnable(bool value) = 0;

            // CH: 个数范围 | EN: Number Range
            __declspec(property(put = SetNumLimitLow, get = GetNumLimitLow)) int NumLimitLow;

            virtual int GetNumLimitLow() = 0;

            virtual void SetNumLimitLow(int value) = 0;

            // CH: 个数范围 | EN: Number Range
            __declspec(property(put = SetNumLimitHigh, get = GetNumLimitHigh)) int NumLimitHigh;

            virtual int GetNumLimitHigh() = 0;

            virtual void SetNumLimitHigh(int value) = 0;

            // CH: 置信度判断 | EN: Confidence Check
            __declspec(property(put = SetScoreLimitEnable, get = GetScoreLimitEnable)) bool ScoreLimitEnable;

            virtual bool GetScoreLimitEnable() = 0;

            virtual void SetScoreLimitEnable(bool value) = 0;

            // CH: 置信度范围 | EN: Confidence Range
            __declspec(property(put = SetScoreLimitLow, get = GetScoreLimitLow)) double ScoreLimitLow;

            virtual double GetScoreLimitLow() = 0;

            virtual void SetScoreLimitLow(double value) = 0;

            // CH: 置信度范围 | EN: Confidence Range
            __declspec(property(put = SetScoreLimitHigh, get = GetScoreLimitHigh)) double ScoreLimitHigh;

            virtual double GetScoreLimitHigh() = 0;

            virtual void SetScoreLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        class ICNNCharDetectPredInfo
        {
        protected:
            ///< Constructor and Destructor
            //构造函数和析构函数
            explicit ICNNCharDetectPredInfo() {};
            virtual ~ICNNCharDetectPredInfo() {};

        public:
            /**
             * @par 说明
             * 预测信息的矩形框
             * @par 权限
             * 只读
             */
            virtual RectBox GetPredictBox() = 0;
            /**
             * @par 说明
             * 预测信息的置信度
             * @par 权限
             * 只读
             */
            virtual float GetConfidence() = 0;
            /**
             * @par 说明
             * 目标状态
             * @par 权限
             * 只读
             */
            virtual float GetObjStatus() = 0;
        };

        /*  Note: Interface Classes of the result of the CnnCharDetectResults.  */
        class CnnCharDetectResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnCharDetectResults() {}
            virtual ~CnnCharDetectResults() {}

        public:
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
             /**
             * @par 说明
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;
            /**
             * @par 说明
             * 预测信息的数量
             * @par 权限
             * 只读
             */
            virtual int GetPredictNumber() = 0;
            /**
             * @par 说明
             * 根据给定的索引获取预测信息
             * @par 权限
             * 只读
             */
            virtual ICNNCharDetectPredInfo* GetPredictInfo(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CnnCharDetect tool.  */
        class IMVSCnnCharDetectModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCnnCharDetectModuTool() {}
            virtual ~IMVSCnnCharDetectModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CnnCharDetectParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CnnCharDetectResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCnnCharDetectModuTool(IMVSCnnCharDetectModuTool&);
            IMVSCnnCharDetectModuTool& operator=(IMVSCnnCharDetectModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CnnCharDetect.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCnnCharDetectModu::IMVSCnnCharDetectModuTool * __stdcall GetCnnCharDetectToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CNNCHARDETECT_H_
