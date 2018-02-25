[%bs.raw {|require("antd/lib/date-picker/style")|}];

[@bs.module]
external reactClass : ReasonReact.reactClass = "antd/lib/date-picker";

[@bs.deriving jsConverter]
type pickerSize = [ | `small | `default | `large];

type moment;

type boolOrTimePickerProps(_) =
  | Bool(bool): boolOrTimePickerProps(bool)
  | TimePickerProps(Antd_TimePicker.timePickerProps('a)): boolOrTimePickerProps(Antd_TimePicker.timePickerProps('a));

let boolOrTimePickerPropsToProp = (type a, boolOrTimePickerProps: boolOrTimePickerProps(a)) : a =>
  switch boolOrTimePickerProps {
  | Bool(bool) => bool
  | TimePickerProps(timePickerProps) => timePickerProps
  };

type datePickerProps('a) = Js.t( {. datePickerProps: int, } as 'a);
[@bs.obj]
external makeDatePickerProps :
  (
    /*export interface DatePickerProps extends PickerProps, SinglePickerProps*/
    ~showTime: 'a=?, /* TimePickerProps | boolean; */
    ~showToday: Js.boolean=?,
    ~_open: Js.boolean=?, /* todo: what do we do about open_ */
    ~disabledTime: 'b=?, /* todo: (current: moment.Moment) => { disabledHours?: () => number[],disabledMinutes?: () => number[], disabledSeconds?: () => number[],}; */
    ~onOpenChange: (Js.boolean)=> unit=?,
    ~onOk: (moment) => unit=?,
    ~placeholder: string=?,

    /*export interface SinglePickerProps*/
    ~value: moment=?,
    ~defaultValue: moment=?,
    ~defaultPickerValue: moment=?,
    ~onChange: (moment, string) => unit=?,

    /*export interface PickerProps*/
    ~prefixCls: string=?,
    ~inputPrefixCls: string=?,
    ~format: string=?,
    ~disabled: Js.boolean=?,
    ~renderExtraFooter: unit => ReasonReact.reactElement =?,
    ~allowClear: Js.boolean=?,
    ~popupStyle: ReactDOMRe.Style.t=?,
    ~locale: 'c=?,
    ~size: string=?,
    ~getCalendarContainer: ('a) => 'b =?, /* todo: (triggerNode: Element) => HTMLElement */
    ~onOpenChange: (Js.boolean)=> unit=?,
    ~disabledDate: (moment) => bool=?,
    ~renderExtraFooter: unit => ReasonReact.reactElement =?,
    ~dateRender: (moment, moment) => ReasonReact.reactElement =?,

    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  datePickerProps(_) =
  "";

let make =
    (
      ~id=?,
      ~className=?,
      ~style=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
    makeDatePickerProps(
        ~id?,
        ~className?,
        ~style?,
        ()
      ),
    children
  );
  
/*
[@bs.obj]
external makeCommonProps :
  (
    ~allowClear: bool=?,
    ~autoFocus: bool=?,
    ~dateRender: (moment, moment) => ReasonReact.reactElement =?,
    ~disabled: bool=?,
    ~disabledDate: (moment) => bool=?,
    ~getCalendarContainer: ('a) => 'b =?, /* todo: (triggerNode: Element) => HTMLElement */
    ~locale: 'c=?,
    ~open_: bool=?, /* todo: what do we do about open_ */
    ~placeholder: 'd, /* todo: string|RangePicker[] */
    ~popupStyle: ReactDOMRe.Style.t=?,
    ~size: string=?,
    ~onOpenChange: (bool)=> unit=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

type pickerProps('a) = Js.t( {. /* whats in here doesn't matter as long as it's unique */ pickerProps: int, } as 'a);
[@bs.obj]
external makePickerProps : 
  (
    ~prefixCls: string=?,
    ~inputPrefixCls: string=?,
    ~format: string=?,
    ~renderExtraFooter: unit => ReasonReact.reactElement =?,
    unit
  ) =>
  pickerProps(_) =
  "";

type singlePickerProps('a) = Js.t( {. singlePickerProps: int, } as 'a);
[@bs.obj]
external makeSinglePickerProps : 
  (
    ~value: moment=?,
    ~defaultValue: moment=?,
    ~defaultPickerValue: moment=?,
    ~onChange: (moment, string) => unit=?,
    unit
  ) =>
  singlePickerProps(_)=
  "";

let make = (~format=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=reactClass,
      ~props=makePickerProps(~format?, ()),
      children
    );

[@bs.obj]
external makeDatePickerProps : 
  (
    ~showTime: 'a=?, /* todo: TimePickerProps | boolean; */
    ~showToday: bool=?,
    ~disabledTime: 'b=?, /* todo: (current: moment.Moment) => { disabledHours?: () => number[],disabledMinutes?: () => number[], disabledSeconds?: () => number[],}; */
    ~onOk: (moment) => unit,
    unit
  ) =>
  _ =
  "";

type rangePickerValue = int;

type stringOrStringArray = int;

[@bs.obj]
external makeRangePickerProps :
  (
    ~ranges: 'a=?, /* todo: {[range: string]: RangePickerPresetRange,}; */
    ~mode: 'b=?, /* string| string[] */
    ~onPanelChange: (rangePickerValue, stringOrStringArray) => unit=?,
    unit
  ) =>
  _ =
  "";

let make = (~name, ~age=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=reactClass,
    ~props=makeSinglePickerProps(~value=4,()),
    children
  );

  */

module RangePicker {

};

module MonthPicker {
};

module WeekPicker {
};