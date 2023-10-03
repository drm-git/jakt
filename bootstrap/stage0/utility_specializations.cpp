#include "utility.h"
#include "main.h"
#include "platform__unknown_compiler.h"
#include "repl.h"
#include "repl_backend__default.h"
#include "repl_backend__common.h"
#include "jakt__libc__io.h"
#include "platform.h"
#include "project.h"
#include "ide.h"
#include "formatter.h"
#include "codegen.h"
#include "typechecker.h"
#include "cpp_import__none.h"
#include "cpp_import__common.h"
#include "jakt__prelude__configuration.h"
#include "interpreter.h"
#include "types.h"
#include "ids.h"
#include "parser.h"
#include "lexer.h"
#include "compiler.h"
#include "error.h"
#include "utility.h"
#include "build.h"
#include "jakt__platform__unknown_process.h"
#include "jakt__file_iterator.h"
#include "jakt__platform__unknown_fs.h"
#include "jakt__path.h"
#include "jakt__platform__unknown_path.h"
#include "jakt__platform.h"
#include "jakt__arguments.h"
#include "jakt__prelude__prelude.h"
#include "jakt__prelude__hash.h"
#include "jakt__prelude__operators.h"
#include "jakt__prelude__string.h"
#include "jakt__prelude__iteration.h"
#include "jakt__prelude__static_array.h"
namespace Jakt {
namespace utility {

/* specialisation 0 of function map: ["parser::ParsedField", "JaktInternal::Tuple<DeprecatedString,utility::Span>"] */
template<> ErrorOr<JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>>> map<parser::ParsedField, JaktInternal::Tuple<DeprecatedString,utility::Span>>(JaktInternal::DynamicArray<parser::ParsedField> const input,Function<ErrorOr<JaktInternal::Tuple<DeprecatedString,utility::Span>>(parser::ParsedField)> const& mapper);

/* specialisation 1 of function map: ["parser::ParsedMethod", "JaktInternal::Tuple<DeprecatedString,utility::Span>"] */
template<> ErrorOr<JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>>> map<parser::ParsedMethod, JaktInternal::Tuple<DeprecatedString,utility::Span>>(JaktInternal::DynamicArray<parser::ParsedMethod> const input,Function<ErrorOr<JaktInternal::Tuple<DeprecatedString,utility::Span>>(parser::ParsedMethod)> const& mapper);

/* specialisation 0 of function null: ["FILE"] */
template<> FILE* null<FILE>();

/* specialisation 1 of function null: ["char"] */
template<> char* null<char>();

/* specialisation 0 of function allocate: ["char"] */
template<> char* allocate<char>(size_t const count);
template<>
ErrorOr<JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>>> map<parser::ParsedField, JaktInternal::Tuple<DeprecatedString,utility::Span>>(JaktInternal::DynamicArray<parser::ParsedField> const input,Function<ErrorOr<JaktInternal::Tuple<DeprecatedString,utility::Span>>(parser::ParsedField)> const& mapper) {
{
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>> us = (TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>>::create_with({}))));
{
JaktInternal::ArrayIterator<parser::ParsedField> _magic = ((input).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedField> const _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedField t = (_magic_value.value());
{
TRY((((us).push(TRY((mapper(t)))))));
}

}
}

return us;
}
}
template<>
ErrorOr<JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>>> map<parser::ParsedMethod, JaktInternal::Tuple<DeprecatedString,utility::Span>>(JaktInternal::DynamicArray<parser::ParsedMethod> const input,Function<ErrorOr<JaktInternal::Tuple<DeprecatedString,utility::Span>>(parser::ParsedMethod)> const& mapper) {
{
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>> us = (TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>>::create_with({}))));
{
JaktInternal::ArrayIterator<parser::ParsedMethod> _magic = ((input).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedMethod> const _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedMethod t = (_magic_value.value());
{
TRY((((us).push(TRY((mapper(t)))))));
}

}
}

return us;
}
}
template<>
FILE* null<FILE>() {
{
{
return nullptr;
}

abort();
}
}
template<>
char* null<char>() {
{
{
return nullptr;
}

abort();
}
}
template<>
char* allocate<char>(size_t const count) {
{
Function<void(char*&)> const alloc_impl = [count](char*& ptr) -> void {
{
{
ptr = static_cast<RemoveReference<decltype(ptr)>>(calloc(count, sizeof(*ptr)));
}

}
}
;
char* ptr = utility::null<char>();
alloc_impl(((ptr)));
return ptr;
}
}
}
} // namespace Jakt
