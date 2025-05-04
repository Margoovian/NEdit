#pragma once
#include <memory>

// This is honestly useless, added to stop auto indenting 
#define NEDIT_INTERNAL_NAMESPACE_START() namespace NEdit::Internal {
#define NEDIT_NAMESPACE_START() namespace NEdit {
#define NEDIT_NAMESPACE_END() }

#define NEDIT_DEFINE_TYPES(type, alias) typedef std::unique_ptr<type> Unique##alias;\
typedef std::shared_ptr<type> Shared##alias;\
typedef std::weak_ptr<type> Weak##alias;\
typedef std::reference_wrapper<type> alias##Ref;\
typedef std::reference_wrapper<const type> alias##CRef;

#define NEDIT_NAMESPACE_END_WITH_TYPE_DEFINES(type, alias) NEDIT_DEFINE_TYPES(type, alias) NEDIT_NAMESPACE_END()

#define NEDIT_DEFINE_NODE()