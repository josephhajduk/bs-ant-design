open Antd_Helpers;

[@bs.module] external menu : ReasonReact.reactClass = "antd/lib/menu";

[%bs.raw {|require("antd/lib/menu/style")|}];

[@bs.deriving jsConverter]
type theme = [ | [@bs.as "light"] `Light | [@bs.as "dark"] `Dark];

[@bs.deriving jsConverter]
type mode = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
  | [@bs.as "vertical-left"] `VerticalLeft
  | [@bs.as "vertical-right"] `VerticalRight
  | [@bs.as "inline"] `Inline
];

type clickParams = {
  .
  "key": string,
  "path": array(string),
  "domEvent": ReactEventRe.Mouse.t
};

[@bs.obj]
external makeProps :
  (
    ~id: string=?,
    ~theme: string=?,
    ~mode: string=?,
    ~selectable: Js.boolean=?,
    ~selectedKeys: array(string)=?,
    ~defaultSelectedKeys: array(string)=?,
    ~openKeys: array(string)=?,
    ~defaultOpenKeys: array(string)=?,
    ~onOpenChange: array(string) => unit=?,
    ~onClick: clickParams => unit=?,
    ~onSelect: clickParams => unit=?,
    ~onDeselect: clickParams => unit=?,
    ~style: ReactDOMRe.Style.t=?,
    ~openTransitionName: string=?,
    ~openAnimation: string=?,
    ~className: string=?,
    ~prefixCls: string=?,
    ~multiple: Js.boolean=?,
    ~inlineIndent: int=?,
    ~inlineCollapsed: Js.boolean=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~theme=?,
      ~mode=?,
      ~selectable=?,
      ~selectedKeys=?,
      ~defaultSelectedKeys=?,
      ~openKeys=?,
      ~defaultOpenKeys=?,
      ~onOpenChange=?,
      ~onSelect=?,
      ~onDeselect=?,
      ~onClick=?,
      ~openTransitionName=?,
      ~openAnimation=?,
      ~className=?,
      ~prefixCls=?,
      ~multiple=?,
      ~inlineIndent=?,
      ~inlineCollapsed=?,
      ~id=?,
      ~style=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=menu,
    ~props=
      makeProps(
        ~theme=?Js.Option.map([@bs] (b => themeToJs(b)), theme),
        ~mode=?Js.Option.map([@bs] (b => modeToJs(b)), mode),
        ~selectable=?Js.Option.map([@bs] (b => from_bool(b)), selectable),
        ~selectedKeys?,
        ~defaultSelectedKeys?,
        ~openKeys?,
        ~defaultOpenKeys?,
        ~onOpenChange?,
        ~onSelect?,
        ~onDeselect?,
        ~onClick?,
        ~openTransitionName?,
        ~openAnimation?,
        ~prefixCls?,
        ~multiple=?Js.Option.map([@bs] (b => from_bool(b)), multiple),
        ~inlineIndent?,
        ~inlineCollapsed=?
          Js.Option.map([@bs] (b => from_bool(b)), inlineCollapsed),
        ~id?,
        ~className?,
        ~style?,
        ()
      ),
    children
  );

module Item = {
  [@bs.module "antd/lib/menu"] external item : ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeProps :
    (
      ~key: string=?,
      ~disabled: Js.boolean=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make = (~disabled=?, ~key_=?, ~id=?, ~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=makeProps(~key=?key_, ~disabled=?Js.Option.map([@bs] (b => from_bool(b)), disabled), ~id?, ~className?, ~style?, ()),
      children
    );
};

module SubMenu = {
  [@bs.module "antd/lib/menu"]
  external subMenu : ReasonReact.reactClass = "SubMenu";
  [@bs.obj]
  external makeProps :
    (
      ~disabled: Js.boolean=?,
      ~key: string=?,
      ~title: ReasonReact.reactElement=?,
      ~onTitleClick: ReactEventRe.Mouse.t=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~disabled=?,
        ~key_=?,
        ~title=?,
        ~onTitleClick=?,
        ~id=?,
        ~className=?,
        ~style=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=subMenu,
      ~props=
        makeProps(
          ~disabled=?Js.Option.map([@bs] (b => from_bool(b)), disabled),
          ~key=?key_,
          ~title?,
          ~onTitleClick?,
          ~id?,
          ~className?,
          ~style?,
          ()
        ),
      children
    );
};

module ItemGroup = {
  [@bs.module "antd/lib/menu"]
  external itemGroup : ReasonReact.reactClass = "ItemGroup";
  [@bs.obj]
  external makeProps :
    (
      ~title: ReasonReact.reactElement=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make = (~id=?, ~className=?, ~style=?, ~title=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=itemGroup,
      ~props=makeProps(~title?, ~id?, ~className?, ~style?, ()),
      children
    );
};

module Divider = {
  [@bs.module "antd/lib/menu"]
  external divider : ReasonReact.reactClass = "Divider";
  [@bs.obj]
  external makeProps :
    (
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make = (~id=?, ~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=divider,
      ~props=makeProps(~id?, ~className?, ~style?, ()),
      children
    );
};