//========================================================================
//
// SharedTerrainSurfaceObjectTemplate.h
//
//IMPORTANT: Any code between //@BEGIN TFD... and //@END TFD... will be
//overwritten the next time the template definition is compiled. Do not
//make changes to code inside these blocks.
//
// copyright 2001 Sony Online Entertainment
//
//========================================================================

#ifndef _INCLUDED_SharedTerrainSurfaceObjectTemplate_H
#define _INCLUDED_SharedTerrainSurfaceObjectTemplate_H

#include "sharedTemplateDefinition/TpfTemplate.h"
#include "../../../../../../engine/shared/library/sharedFoundation/include/public/sharedFoundation/DynamicVariable.h"
#include "sharedTemplateDefinition/TpfTemplate.h"


class Vector;
typedef StructParam<ObjectTemplate> StructParamOT;


class SharedTerrainSurfaceObjectTemplate : public TpfTemplate
{
public:
//@BEGIN TFD ID
	enum
	{
		SharedTerrainSurfaceObjectTemplate_tag = TAG(S,T,E,R)
	};
//@END TFD ID
public:
	         SharedTerrainSurfaceObjectTemplate(const std::string & filename);
	virtual ~SharedTerrainSurfaceObjectTemplate();

	virtual Tag getId(void) const;
	virtual Tag getTemplateVersion(void) const;
	virtual Tag getHighestTemplateVersion(void) const;
	static void install(void);

//@BEGIN TFD
public:
	virtual CompilerIntegerParam *getCompilerIntegerParam(const char *name, bool deepCheck = true, int index = 0);
	virtual FloatParam *getFloatParam(const char *name, bool deepCheck = true, int index = 0);
	virtual BoolParam *getBoolParam(const char *name, bool deepCheck = true, int index = 0);
	virtual StringParam *getStringParam(const char *name, bool deepCheck = true, int index = 0);
	virtual StringIdParam *getStringIdParam(const char *name, bool deepCheck = true, int index = 0);
	virtual VectorParam *getVectorParam(const char *name, bool deepCheck = true, int index = 0);
	virtual DynamicVariableParam *getDynamicVariableParam(const char *name, bool deepCheck = true, int index = 0);
	virtual StructParamOT *getStructParamOT(const char *name, bool deepCheck = true, int index = 0);
	virtual TriggerVolumeParam *getTriggerVolumeParam(const char *name, bool deepCheck = true, int index = 0);
	virtual void initStructParamOT(StructParamOT &param, const char *name);
	virtual void setAsEmptyList(const char *name);
	virtual void setAppend(const char *name);
	virtual bool isAppend(const char *name) const;
	virtual int getListLength(const char *name) const;

protected:
	virtual void load(Iff &file);
	virtual void save(Iff &file);

private:
	FloatParam m_cover;
	StringParam m_surfaceType;
//@END TFD

private:
	Tag  m_templateVersion;	// the template version
	bool m_versionOk;	// flag that the template version loaded is the one we expect

	static void registerMe(void);
	static ObjectTemplate * create(const std::string & filename);

	// no copying
	SharedTerrainSurfaceObjectTemplate(const SharedTerrainSurfaceObjectTemplate &);
	SharedTerrainSurfaceObjectTemplate & operator =(const SharedTerrainSurfaceObjectTemplate &);
};


inline void SharedTerrainSurfaceObjectTemplate::install(void)
{
//@BEGIN TFD INSTALL
	SharedTerrainSurfaceObjectTemplate::registerMe();
//@END TFD INSTALL
}


#endif	// _INCLUDED_SharedTerrainSurfaceObjectTemplate_H